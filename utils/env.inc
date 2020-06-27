<%
function GetEnv(envVar)

    set shellExec = createobject("WScript.Shell")
    Set objSystemVariables = shellExec.Environment("SYSTEM")
    GetEnv = objSystemVariables(envVar)

end function
%>