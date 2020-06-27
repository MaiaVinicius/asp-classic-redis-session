<!--#include file="encrypt_decrypt.inc"-->
<!--#include file="./../env.inc"-->
<%
APP_SALT = GetEnv("APP_SALT")
if APP_SALT="" then
    call Err.Raise( 10, "SaltString", "Variable APP_SALT not set")
end if

function setAuthCookie(user)
    signed = EnDeCrypt(user, APP_SALT)
    Response.Cookies("u")= signed
end function

function decodeAuthCookie()
    authCookie = Request.Cookies("u")
    decodeAuthCookie = EnDeCrypt(authCookie, APP_SALT)
end function

%>