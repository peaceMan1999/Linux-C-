#pragma once
#include <iostream>
#include <cstdlib>
#include <unistd.h>
#include <cstring>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/select.h>
#include <netinet/in.h>



namespace yz_sk{
    
    class Sock{
        public:
            static int Socket()
            {
                int sock = socket(AF_INET, SOCK_STREAM, 0);
                if (sock < 0){
                    std::cerr << "socket err" << std::endl;
                    exit(1);
                }
                int opt = 1;
                setsockopt(sock, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));
                return sock;
            }

            static bool Bind(int sock, unsigned short port)
            {
                struct sockaddr_in local;
                memset(&local, 0, sizeof(local));
                local.sin_family = AF_INET;
                local.sin_port = htons(port);
                local.sin_addr.s_addr = INADDR_ANY;

                if (bind(sock, (struct sockaddr*)&local, sizeof(local)) < 0){
                    std::cerr << "bind err" << std::endl;
                    exit(2);
                }

                return true;
            }
            static bool Listen(int sock, int backlog)
            {
                if (listen(sock, backlog) < 0){
                    std::cerr << "listen err" << std::endl;
                    exit(3);
                }
                return true;
            }
    };


}





