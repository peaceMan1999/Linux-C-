#pragma once

#include "sock.hpp"
#include <sys/poll.h>

namespace yz_poll{
#define DEF_LOG 5

    class Poll_Server{
        private:
            int listen_sock;
            unsigned short port;
        public:
            Poll_Server(unsigned short _port):port(_port)
            {}

            void InitPoll()
            {
                listen_sock = yz_sk::Sock::Socket();
                yz_sk::Sock::Bind(listen_sock, port);
                yz_sk::Sock::Listen(listen_sock, DEF_LOG);
            }

            void Run()
            {
                struct pollfd rfds[64];
                for (int i = 0; i < 64; i++){
                    rfds[i].fd = -1;
                    rfds[i].events = 0;
                    rfds[i].revents = 0;
                }
                rfds[0].fd = listen_sock;
                rfds[0].events |= POLLIN;
                rfds[0].revents = 0;

                for (;;){
                    switch(poll(rfds, 64, -1)){
                        case 0:
                            std::cout << "timeout" << std::endl;
                            break;
                        case -1:
                            std::cerr << "poll err" << std::endl;
                            break;
                        default:
                            for (int i = 0; i < 64; i++){
                                if (rfds[i].fd == -1){
                                    continue;
                                }
                                if (rfds[i].revents & POLLIN){
                                    if (rfds[i].fd == listen_sock){
                                        //accept
                                        std::cout << "get a link" << std::endl;
                                    }
                                    else{
                                        // recv
                                    }
                                }
                            }
                            break;
                    }
                }

            }

            ~Poll_Server()
            {}
    };


}


