# TCP1
这是我的一个简单的基于TCP协议下的客户端与服务器端的信息传输项目（TCP套接字编程）。
实现功能：
        1.客户端能在保持TCP连接的前提下，多次发送数据到服务器端。
        2.服务器端在收到了客户端的数据前提下，将小写字母转换成大写字母并回传给客户端。
        3.在收到特殊的字符之后，服务器端回传同时告诉客户端关闭套接字。客户端收到并关闭套接字（程序结束）。
代码注意：
        1.这是一个基于WinSock2下的程序。
        2.一个解决方案中，有两个项目，先将NET2项目设为启动项运行之后，再将NET3项目设为启动项运行。