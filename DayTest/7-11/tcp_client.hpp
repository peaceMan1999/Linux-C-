#pragma once

#include <iostream>
#include <sys/types.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <string>
#include <cstring>
#include <unistd.h>

class TcpClient{
    private:
        std::string _ip;
        int _port;
        int _sock;
    public:
        TcpClient(std::string ip, int port)
            :_ip(ip)
             , _port(port)
             , _sock(-1)
        {}

        void InitTcpClient()
        {
            _sock = socket(AF_INET, SOCK_STREAM, 0);
            if (_sock < 0){
                std::cerr << "socket err" << std::endl;
                exit(2);
            }
        }

        void Start()
        {
            struct sockaddr_in peer;
            memset(&peer, '\0', sizeof(peer));

            peer.sin_family = AF_INET;
            peer.sin_port = htons(_port);
            peer.sin_addr.s_addr = inet_addr(_ip.c_str());

            if (connect(_sock, (struct sockaddr*)&peer, sizeof(peer)) == 0){
                std::cout << "connect success" << std::endl;
                Request(_sock);
            }else{
                std::cerr << "connect fail ..." << std::endl;
            }
        }

        void Request(int sock)
        {
            char buffer[128];
            std::string msg;
            while(true){
                std::cout << "Please Enter# ";
                std::cin >> msg;
                
                write(sock, msg.c_str(), msg.size());

                ssize_t s = read(sock, &buffer, sizeof(buffer)-1);
                if (s > 0){
                    buffer[s] = 0;
                    std::cout << "Server echo#" << buffer << std::endl; 
                }
            }
        }

        ~TcpClient(){if (_sock >= 0) close(_sock);}

};

