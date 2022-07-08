#include "udp_server.hpp"

int main(int argc, char* argv[])
{
    if (argc != 2){
        std::cerr << "Usage"<< argv[0] << "need port" << std::endl;
        return 1;
    }
    
    int port = atoi(argv[1]);
   // std::string ip = "127.0.0.1"; // 本地环回 

    UdpServer *srv = new UdpServer(port);
    srv->InitUdpServer();

    srv->start();

    return 0;
}
