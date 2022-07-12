#include <iostream>
#include <unistd.h>
#include <sys/types.h>
#include <fstream>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <sys/wait.h>
#include <cstdlib>
#include <string>
#include <cstring>
#include <netinet/in.h>

int main()
{
    int lsock = socket(AF_INET, SOCK_STREAM, 0);
    if (lsock < 0){
        std::cerr << "socket err" << std::endl;
        return 1;
    }

    struct sockaddr_in local;
    memset(&local, '\0', sizeof(local));
    local.sin_family = AF_INET;
    local.sin_port = htons(8081);
    local.sin_addr.s_addr = INADDR_ANY;

    if (bind(lsock, (struct sockaddr*)&local, sizeof(local)) < 0){
        std::cerr << "bind err" << std::endl;
        return 2;
    }

    if (listen(lsock, 5) < 0){
        std::cerr << "listen err" << std::endl;
        return 3;
    }
    
    struct sockaddr_in peer;
    for ( ; ; ){
        socklen_t len = sizeof(peer);
        int sock = accept(lsock, (struct sockaddr*)&peer, &len);
        if (sock < 0){
            std::cerr << "accept err" << std::endl;
            continue;
        }
        
        if (fork() == 0){
            if (fork() > 0){
                exit(0);
            }
            close(lsock);
            // 读
            char buffer[1024];
            recv(sock, &buffer, sizeof(buffer), 0);
            
            std::cout << "############################# http request begin #################################" << std::endl;
            
            std::cout << buffer << std::endl;
            
            std::cout << "############################# http request end   #################################" << std::endl;

#define PAGE "index.html"

            std::ifstream in(PAGE);
            if(in.is_open()){
                in.seekg(0, std::ios::end);
                size_t len = in.tellg();
                in.seekg(0, std::ios::beg);
                char *file = new char[len];
                in.read(file, len);
                in.close();
            
            
                std::string status_line = "http/1.1 200 OK\n";
                std::string response_header="Content-Length: " + std::to_string(len);
                response_header += "\n";
                response_header += "Set-Cookie: abcdefg12345;\n";
                std::string blank="\n";

                send(sock, status_line.c_str(), status_line.size(), 0);
                send(sock, response_header.c_str(), response_header.size(), 0);
                send(sock, blank.c_str(), blank.size(), 0);

                send(sock, file, len, 0);

                delete[] file;
            }
            close(sock);
            exit(0);
        }
        close(sock);
        waitpid(-1, nullptr, 0);
    }


}
