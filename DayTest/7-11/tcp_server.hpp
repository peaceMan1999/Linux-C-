#pragma once

#include <netinet/in.h>
#include <string>
#include <cstring>
#include <sys/wait.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <iostream>
#include <sys/socket.h>
#include <sys/types.h>

#define DEFAULT 8081
#define BackLog 5

class TcpServer{
    private:
        int _port; // 端口号
        int _lsock; // listen_sockfd 监听套接字
    public:
        TcpServer(int port = DEFAULT)
            :_port(port), _lsock(-1)
        {}

        void InitTcpServer()
        {
            _lsock = socket(AF_INET, SOCK_STREAM, 0);
            if (_lsock < 0){
                std::cerr << "socket err" << std::endl;
                exit(2);
            }

            struct sockaddr_in local;
            memset(&local, '\0', sizeof(local));
            local.sin_family = AF_INET;
            local.sin_port = htons(_port);
            local.sin_addr.s_addr = INADDR_ANY;
            
            if (bind(_lsock, (struct sockaddr*)&local, sizeof(local)) < 0){
                std::cerr << "bind err" << std::endl;
                exit(3);
            }

            if (listen(_lsock, BackLog) < 0){
                std::cerr << "listen err" << std::endl;
                exit(4);
            }
        }

        void Loop()
        {
            struct sockaddr_in peer;

            for ( ; ; ){
                socklen_t len = sizeof(peer);
                int sock = accept(_lsock, (struct sockaddr*)&peer, &len);
                if (sock < 0){
                    std::cout << "accept err" << std::endl;
                    continue;
                }
                
                // 创建爷孙进程
                pid_t id = fork();
                if (id == 0){
                    close(_lsock);
                    if (fork() > 0){
                        exit(0);
                    }
                    std::string ip = inet_ntoa(peer.sin_addr);
                    int port = ntohs(peer.sin_port);
                    std::cout << "get a link->" << sock << " # [" << ip << ":" << port << "] :" << std::endl;
                    
                    Server(sock, ip, port);
                    exit(0);
                }
                // father
                close(sock);
                waitpid(id, nullptr, 0);
            }
        }
        
        void Server(int sock, std::string ip, int port)
        {
            char buffer[128];
            
            while (true){
                ssize_t s = read(sock, buffer, sizeof(buffer)-1);
                if (s > 0){
                    buffer[s] = 0;
                    std::cout << ip << ":" << port << "# " << buffer << std::endl;
                    
                    write(sock, buffer, s);
                }else if (s == 0){
                    std::cout << "client close" << std::endl;
                    break;
                }else{
                    std::cerr << "read err" << std::endl;
                    break;
                }
            }
            std::cout << "Server done" << std::endl;
        }

        ~TcpServer(){
            if (_lsock >= 0) close(_lsock);
        }

};

