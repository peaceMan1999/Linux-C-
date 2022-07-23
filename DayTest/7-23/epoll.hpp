#pragma once

#include "sock.hpp"
#include <sys/epoll.h>

namespace yz_epoll{
#define MAXNUM 64
    class EpollServer{
        private:
            int listen_sock;
            uint16_t port;
            int epfd; // 管理信息的文件描述符
        public:
            EpollServer(uint16_t _port):port(_port)
            {}
            
            void InitEpoll()
            {
                listen_sock = yz_sk::Sock::Socket();
                yz_sk::Sock::Bind(listen_sock, port);
                yz_sk::Sock::Listen(listen_sock, 5);

                std::cout << "listen_sock" << listen_sock << std::endl;

                epfd = epoll_create(256);
                if (epfd < 0){
                    std::cerr << "epoll_create err" << std::endl;
                    exit(4);
                }
                std::cout << "epfd" << epfd << std::endl;
            }
            
            void AddEvent(int sock, uint32_t event)
            {
                struct epoll_event ev;
                ev.events = 0;
                ev.events |= event; // 清空 
                ev.data.fd = sock;
                if (epoll_ctl(epfd, EPOLL_CTL_ADD, sock, &ev) < 0){
                    std::cerr << "epoll_ctl err, fd: " << sock << std::endl;
                }
            }
            void DelEvent(int sock)
            {
                if (epoll_ctl(epfd, EPOLL_CTL_DEL, sock, nullptr) < 0){
                    std::cerr << "epfd close fd : " << sock << std::endl;
                }
            }
            void Run()
            {
                // 目前只有listen_sock
                AddEvent(listen_sock, EPOLLIN);
                int timeout = -1;
                struct epoll_event revs[MAXNUM];
                for (;;){
                    // 返回值num表明有多少个事件就绪，内核会将就绪事件放进revs中
                    int num = epoll_wait(epfd, revs, MAXNUM, timeout);
                    if (num > 0){
                        // 有事件 
                        for (int i = 0; i < num; i++){
                            int sock = revs[i].data.fd;
                            // 判断是哪种就绪
                            if (sock == listen_sock){
                                // 链接事件
                                struct sockaddr_in peer;
                                socklen_t len = sizeof(peer);
                                int sk = accept(sock, (struct sockaddr*)&peer, &len);
                                if (sk < 0){
                                    std::cout << "accept err" << std::endl;
                                    continue;
                                }
                                std::cout << inet_ntoa(peer.sin_addr) << ":" << ntohs(peer.sin_port) << std::endl;
                                AddEvent(sk, EPOLLIN);
                                // 要把新的添加到里面
                            }else{
                                // 可读事件
                                char buff[1024];
                                ssize_t s = recv(sock, buff, sizeof(buff)-1, 0);
                                if (s > 0){
                                    buff[s] = 0;
                                    std::cout << buff << std::endl;
                                }else if (s == 0){
                                    std::cout << "client end" << std::endl;
                                    close(sock);
                                    DelEvent(sock);
                                }else{
                                    close(sock);
                                    DelEvent(sock);
                                }
                            }
                        }
                    }else if (num == 0){
                        std::cout << "timeout" << std::endl;
                    }else{
                        std::cout << "epoll err" << std::endl;
                        // ..
                    }
                }
            }

            ~EpollServer()
            {
                if (listen_sock >= 0) close(listen_sock);
                if (epfd >= 0) close(epfd);
            }
    };

}
