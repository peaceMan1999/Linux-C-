#pragma once

#include "sock.hpp"

#define DEF_LOG 5
#define NUM 1024
#define DEF_FD -1

namespace yz_ss{

    class SelectServer
    {
        private:
            int listen_sock;
            unsigned short port;
        public:
            SelectServer(unsigned short _port): port(_port)
            {}

            void InitSS()
            {
                listen_sock = yz_sk::Sock::Socket();
                yz_sk::Sock::Bind(listen_sock, port);
                yz_sk::Sock::Listen(listen_sock, DEF_LOG);
            }
            
            void Run()
            {
                fd_set rfds;
                int fd_array[NUM] = {0};
                ClearArray(fd_array, NUM, DEF_FD);

                // 第一个写上链接
                fd_array[0] = listen_sock;

                for (;;){
                    // 设置等待时间
                    struct timeval timeout = {5, 0};
                    // 设置最大fd
                    int max_fd = DEF_FD;
                    // 清空所有readfd
                    FD_ZERO(&rfds);
                    // 第一次循环至少有一个listen_fd
                    for (auto i = 0; i < NUM; i++){
                        if (fd_array[i] == DEF_FD){
                            continue;
                        }
                        // 说明是需要添加的合法fd
                        FD_SET(fd_array[i], &rfds);
                        if(fd_array[i] > max_fd){
                            max_fd = fd_array[i]; // 更新最大fd
                        }
                    }
                    // 1、阻塞等待
                    // 2、timeval={0}，非阻塞
                    // 3、阻塞+轮询 = {5，0}；5s内阻塞等待，5s后select返回
                    switch(select(max_fd+1, &rfds, nullptr, nullptr, &timeout/*nullptr*/)){
                            case 0:
                                std::cout << "timeout: " << timeout.tv_sec << std::endl;
                                break;
                            case -1:
                                std::cerr << "select err" << std::endl;
                                break;
                            default:
                                // 正常处理
                                Handler(rfds, fd_array, NUM);
                                break;
                    }
                }
            }

            void Handler(const fd_set &rfds, int fd_array[], int num)
            {
                for (auto i = 0; i < num; i++){
                    // 过滤掉不需要的fd
                    if (fd_array[i] == DEF_FD){
                        continue;
                    }

                    // 合法，但不一定就绪
                    if (fd_array[i] == listen_sock && FD_ISSET(fd_array[i], &rfds)){
                        // 是连接到来
                        struct sockaddr_in peer;
                        socklen_t len = sizeof(peer);
                        int sock = accept(listen_sock, (struct sockaddr*)&peer, &len);
                        if (sock < 0){
                            std::cerr << "accept err" << std::endl;
                            continue;
                        }
                        uint16_t peer_port = htons(peer.sin_port);
                        std::string peer_ip = inet_ntoa(peer.sin_addr);
                        
                        std::cout << "get a link : " << peer_ip << " : " << peer_port << std::endl;
                        if (!AddFD(fd_array, num, sock)){
                            close(sock);
                            std::cout << "满了" << std::endl;
                        }
                    }else{
                        if (FD_ISSET(fd_array[i], &rfds)){
                            // 是一个合法
                            char buff[1024];
                            ssize_t s = recv(fd_array[i], buff, sizeof(buff)-1, 0);
                            if (s > 0){
                                buff[s] = 0;
                                std::cout << "echo# " << buff << std::endl;
                            }else if(s == 0){
                                std::cout << "client quit" << std::endl;
                                close(fd_array[i]);
                                fd_array[i] = DEF_FD;
                            }else{
                                std::cerr << "recv err" << std::endl;
                                close(fd_array[i]);
                                fd_array[i] = DEF_FD;
                            }
                        }
                    }
                }
            }

        private:
            void ClearArray(int fd_array[], int num, int def_fd)
            {
                for (auto i = 0; i < num; i++){
                    fd_array[i] = def_fd;
                }

            }

            bool AddFD(int fd_array[], int num, int sock)
            {
                // 初始化所有fd
                for (int i = 0; i < num; i++)
                {
                    if (fd_array[i] == DEF_FD){
                        // 说明该位置没有被使用
                        fd_array[i] = sock;
                        return true;
                    }
                }
                // 说明我们数组内可见已经用完了
                return false;
                
            }


            ~SelectServer()
            {}
        
    };








}



