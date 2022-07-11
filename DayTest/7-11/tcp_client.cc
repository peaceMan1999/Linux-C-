#include "tcp_client.hpp"

int main(int argc, char *argv[])
{
    if (argc != 3){
        std::cerr << "Usage:" << argv[0] << "ip and port" << std::endl;
        exit(1);
    }

    std::string ip = argv[1];
    int port = atoi(argv[2]);

    TcpClient clt(ip, port);

    clt.InitTcpClient();
    clt.Start();

    return 0;
}
