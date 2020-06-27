<!--#include file="./../env.inc"-->
<!--#include file="auth_cookie.inc"-->
<%
REDIS_CONNECTION_STRING = GetEnv("REDIS_CONN")

if REDIS_CONNECTION_STRING="" then
    call Err.Raise( 10, "RedisConnection", "Variable REDIS_CONNECTION_STRING not set")
end if

'value in seconds for the session to live
SESSION_EXPIRATION = 60 * 60 * 6

Set Redis = Server.CreateObject("RedisComClient")
' Pass in a configuration to connect to a server
Redis.Open(REDIS_CONNECTION_STRING)


function setSession(key, val)
    user_id = decodeAuthCookie()
    key = user_id & ":" & key

    call Redis.Set(key, val, SESSION_EXPIRATION)
end function

function session(key)
    user_id = decodeAuthCookie()
    key = user_id & ":" & key
    
    session=Redis.Get(key)
end function

function initSession(user_id)
    if user_id<>"" then
        call setSession("SessionState", "ACTIVE")
    end if
end function

%>