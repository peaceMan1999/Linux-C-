#include "poll.hpp"

int main(int argc, char *argv[])
{
    // exe port
    if (argc != 2){
        std::cout << "Usage : " << argv[0] << " port " << std::endl;
        exit(4);
    }
    unsigned short port = atoi(argv[1]);

    yz_poll::Poll_Server *srv = new yz_poll::Poll_Server(port);

    srv->InitPoll();
    srv->Run();

    return 0;
}
