/*
 * $Source$
 * $Author$
 *
 * Copyright 1990 by the Massachusetts Institute of Technology.
 *
 * For copying and distribution information, please see the file
 * <krb5/mit-copyright.h>.
 *
 * krb5_free_enc_kdc_rep_part()
 */

#if !defined(lint) && !defined(SABER)
static char f_enc_kdc_c [] =
"$Id$";
#endif	/* !lint & !SABER */

#include <krb5/copyright.h>
#include <krb5/krb5.h>

void
krb5_free_enc_kdc_rep_part(val)
register krb5_enc_kdc_rep_part *val;
{
    if (val->session)
	krb5_free_keyblock(val->session);
    if (val->last_req)
	krb5_free_last_req(val->last_req);
    if (val->server)
	krb5_free_principal(val->server);
    if (val->caddrs)
	krb5_free_address(val->caddrs);
    xfree(val);
    return;
}
