#pragma once

#include <iostream>
#include <sys/socket.h>
#include <string.h>
#include <sys/types.h>
#include <string>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include <unistd.h>

using namespace std;

class Sock
{
public:
    // 1、创建套接字
    static int Socket()
    {
        int sock = socket(AF_INET, SOCK_STREAM, 0);
        if (sock < 0)
        {
            cout << "sock err" << endl;
            exit(2);
        }
        return sock;
    }

    // 2、绑定
    static void Bind(int sock, uint16_t port)
    {
        struct sockaddr_in local;
        local.sin_family = AF_INET;
        local.sin_port = htons(port);
        local.sin_addr.s_addr = INADDR_ANY;

        if (bind(sock, (struct sockaddr *)&local, sizeof(local)) < 0)
        {
            cout << "bind err" << endl;
            exit(3);
        }
    }

    // 3、监听
    static void Listen(int sock)
    {
        if (listen(sock, 5) < 0)
        {
            cout << "listen err" << endl;
            exit(4);
        }
    }

    // 4、链接
    static int Accept(int sock)
    {
        struct sockaddr_in peer;
        socklen_t len = sizeof(peer);

        int fd = accept(sock, (struct sockaddr *)&peer, &len);
        // cout << "in" << endl;
        if (fd >= 0)
        {
            // cout << fd << endl;
            return fd;
        }
        return -1;
    }

    // 5、建立连接 -- 客户端
    static void Connect(int sock, string ip, uint16_t port)
    {
        struct sockaddr_in server;
        server.sin_family = AF_INET;
        server.sin_port = htons(port);
        server.sin_addr.s_addr = inet_addr(ip.c_str());

        if (connect(sock, (struct sockaddr *)&server, sizeof(server)) != 0)
        {
            cout << "connect err" << endl;
            exit(5);
        }
        else
        {
            cout << "connect success!" << endl;
        }
    }
};
// #pragma once

// #include <iostream>
// #include <string>
// #include <cstring>
// #include <cstdlib>
// #include <sys/socket.h>
// #include <netinet/in.h>
// #include <arpa/inet.h>
// #include <unistd.h>

// using namespace std;

// class Sock
// {
// public:
//     static int Socket()
//     {
//         int sock = socket(AF_INET, SOCK_STREAM, 0);
//         if (sock < 0)
//         {
//             cerr << "socket error" << endl;
//             exit(2);
//         }
//         int opt = 1;
//         setsockopt(sock, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));
//         return sock;
//     }

//     static void Bind(int sock, uint16_t port)
//     {
//         struct sockaddr_in local;
//         memset(&local, 0, sizeof(local));
//         local.sin_family = AF_INET;
//         local.sin_port = htons(port);
//         local.sin_addr.s_addr = INADDR_ANY;

//         if (bind(sock, (struct sockaddr *)&local, sizeof(local)) < 0)
//         {
//             cerr << "bind error!" << endl;
//             exit(3);
//         }
//     }

//     static void Listen(int sock)
//     {
//         if (listen(sock, 5) < 0)
//         {
//             cerr << "listen error !" << endl;
//             exit(4);
//         }
//     }

//     static int Accept(int sock)
//     {
//         struct sockaddr_in peer;
//         socklen_t len = sizeof(peer);
//         int fd = accept(sock, (struct sockaddr *)&peer, &len);
//         if(fd >= 0){
//             return fd;
//         }
//         return -1;
//     }

//     static void Connect(int sock, std::string ip, uint16_t port)
//     {
//         struct sockaddr_in server;
//         memset(&server, 0, sizeof(server));

//         server.sin_family = AF_INET;
//         server.sin_port = htons(port);
//         server.sin_addr.s_addr = inet_addr(ip.c_str());

//         if(connect(sock, (struct sockaddr*)&server, sizeof(server)) == 0)
//         {
//             cout << "Connect Success!" << endl;
//         }
//         else
//         {
//             cout << "Connect Failed!" << endl;
//             exit(5);
//         }
//     }
// };