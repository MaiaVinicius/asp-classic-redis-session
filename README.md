# asp-classic-redis-session

Provides a way to change the default Asp Classic Session State to a Redis Session aproach.


#### Usage

- Clone this repo to `\inetpub\wwwroot\redis-session`
- Create some Environment Variables
    - `APP_SALT` : Some encrypted string to be used to generate the cookie
    - `REDIS_CONN` : The Redis Connection String (See [this](https://stackexchange.github.io/StackExchange.Redis/Configuration.html#basic-configuration-strings) to understand)
- Go to `http://localhost/redis-session/start_session_example.asp` that simulates a successfull login
- Then go to `http://localhost/redis-session/internal_page_example.asp`
- Test the logout in `http://localhost/redis-session/logout_example.asp`


#### How it works

###### Redis Connection
Using [redis-com-client](https://github.com/MaiaVinicius/redis-com-client) to connect the Asp Classic to Redis server.


###### 1) Login
- When the user does the login, we create a encrypted cookie containing the `user_id` or the `key`
- On every request we decode that `key` to get back the `user_id`


###### 2) Retrieve a session value
- Once we have the `user_id` extracted from a cookie, we can ask for a redis server some session variable

> Ok, now you can use some cool features such as AWS Load Balancer and Auto Scaling, since the Asp Session State will not be attached to a single instance anymore :)
