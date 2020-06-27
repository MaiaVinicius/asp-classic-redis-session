<!--#include file="utils/auth/session.inc"-->
<%
call setSession("SessionState", "INACTIVE")
call setSession("ID", 0)

' Response.Cookies("u")= ""

%>
<h3>Logout Successfull.</h3>