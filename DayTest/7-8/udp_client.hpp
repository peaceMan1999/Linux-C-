#pragma once

#include <arpa/inet.h>
#include <netinet/in.h>
#include <cstring>
#include <iostream>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>


class UdpClient{
    private:
        int _sockfd;
        std::string _ip;
        int server_port;
    public:
        UdpClient(std::string ip, int port)
            :_ip(ip),
            server_port(port)
        {}
        
        bool InitUdpClient()
        {
            _sockfd = socket(AF_INET, SOCK_DGRAM, 0);
            if (_sockfd < 0){
                std::cerr << "socket err" << std::endl;
                return false;
            }
            
            // 客户端不需要绑定
            return true;
        }
    
        void start()
        {
            struct sockaddr_in peer;
            memset(&peer, '\0', sizeof(peer));
            
            peer.sin_family = AF_INET;
            peer.sin_port = htons(server_port);
            peer.sin_addr.s_addr = inet_addr(_ip.c_str());

            std::string msg;
            for ( ; ; )
            {
                std::cout << "Please Enter : ";
                std::cin >> msg;
                sendto(_sockfd, msg.c_str(), msg.size(), 0, (struct sockaddr*)&peer, sizeof(peer));

                //char buffer[128];
                //struct sockaddr_in temp;
                //socklen_t len = sizeof(temp);
                //ssize_t s = recvfrom(_sockfd, buffer, sizeof(buffer)-1, 0, (struct sockaddr*)&temp, &len);
                //if (s > 0){
                //    buffer[s] = 0;
                //    std::cout << buffer << std::endl;
                //} 
            }
        }

        ~UdpClient()
        {
            if (_sockfd >= 0) close(_sockfd);
        }

};
