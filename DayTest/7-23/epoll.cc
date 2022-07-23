#include "epoll.hpp"

int main(int argc, char *argv[])
{
    // exe port
    if (argc != 2){
        std::cout << "Usage : " << argv[0] << " port " << std::endl;
        exit(4);
    }
    unsigned short port = atoi(argv[1]);

    yz_epoll::EpollServer *srv = new yz_epoll::EpollServer(port);

    srv->InitEpoll();
    srv->Run();

    return 0;
}
