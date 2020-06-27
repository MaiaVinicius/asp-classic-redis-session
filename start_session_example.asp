<!--#include file="utils/auth/session.inc"-->
<%
' login
logged_user_id = 999

setAuthCookie(logged_user_id)


' initiate session
call initSession(logged_user_id)

call setSession("ID", logged_user_id)
call setSession("Name", "JOHN DOE")
call setSession("Picture", "user-pic.png")
call setSession("Permissions", "[...]")

%>
<h3>Session started successfully.</h3>