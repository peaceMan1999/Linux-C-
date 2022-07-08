#pragma once

#include <unistd.h>
#include <iostream>
#include <sys/socket.h>
#include <sys/types.h>
#include <cstring>
#include <arpa/inet.h>
#include <netinet/in.h>

#define DEFAULT 8081

class UdpServer{
    private:
        int _port; // 端口
        int _sockfd; // 套接字
        // std::string _ip; // ip
    public:
        UdpServer(int port = DEFAULT)
            :_port(port),
            _sockfd(-1)
           // _ip(ip)
        {}

        bool InitUdpServer()
        {
            _sockfd = socket(AF_INET, SOCK_DGRAM, 0);
            if (_sockfd < 0){
                std::cerr << "socker err" << std::endl;
                return false;
            }

            struct sockaddr_in local;
            memset(&local, '\0', sizeof(local));
            local.sin_family = AF_INET;
            local.sin_port = htons(_port);
            local.sin_addr.s_addr = INADDR_ANY; // inet_addr(_ip.c_str());

            if (bind(_sockfd, (struct sockaddr*) &local, sizeof(local)) < 0){
                std::cerr << "bind err" << std::endl;
                return false;
            }
            std::cout << "bind success" << std::endl;

            return true;
        }

        void start()
        {
#define SIZE 128
            char buffer[SIZE];
            
            for( ; ; )
            {
                struct sockaddr_in peer; // 对端
                socklen_t addrlen = sizeof(peer);
                ssize_t s = recvfrom(_sockfd, buffer, sizeof(buffer)-1, 0, (struct sockaddr*) &peer, &addrlen);
                if (s > 0){
                    buffer[s] = 0;
                    int port = ntohs(peer.sin_port);
                    std::string ip = inet_ntoa(peer.sin_addr);
                    
                    std::cout << ip << ":" << port << "#  " << buffer << std::endl;
                }
                else{
                    std::cerr << "recvform err" << std::endl;
                }
            }
        }

        ~UdpServer()
        {
            if (_sockfd >= 0) close(_sockfd);
        }

};
