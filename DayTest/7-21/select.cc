#include "select_server.hpp"

int main(int argc, char *argv[])
{
    // exe port
    if (argc != 2){
        std::cout << "Usage : " << argv[0] << " port " << std::endl;
        exit(4);
    }
    unsigned short port = atoi(argv[1]);

    yz_ss::SelectServer *srv = new yz_ss::SelectServer(port);

    srv->InitSS();
    srv->Run();

    return 0;
}
