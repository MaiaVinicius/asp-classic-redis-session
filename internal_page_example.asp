<!--#include file="utils/auth/session.inc"-->
<h3>Simulating a internal page that requires user_session</h3>
<%

is_logged = session("SessionState")

if is_logged <> "ACTIVE" then
    
    Response.write("403: Not Authorized!")
    Response.End
end if

response.write("LOGIN OK! <br>")

' use session
response.write("some session value:   " &session("Name"))

%>