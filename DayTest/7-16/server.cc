#include <iostream>
#include <pthread.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <unistd.h>
#include <string>
#include <cstring>
#include <sys/types.h>
#include <sys/socket.h>
#include <cstdlib>

using std::cerr;
using std::endl;
using std::cout;

#define port 8081
#define NUM 5

void* Routinue(void *arg)
{
    pthread_detach(pthread_self());
    int sock = *(int*)arg;
    delete (int*)arg;
   
    while (1){
        cout << "thread running : " << pthread_self() << endl;
        sleep(1);
    }

    //return nullptr;
}

int main()
{
    int lsock = socket(AF_INET, SOCK_STREAM, 0);
    if (lsock < 0){
        cerr << "socket err" << endl;
    }

    int opt = 1;
    setsockopt(lsock, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));

    struct sockaddr_in local;
    local.sin_family = AF_INET;
    local.sin_port = htons(port);
    local.sin_addr.s_addr = INADDR_ANY;

    if (bind(lsock, (struct sockaddr*)&local, sizeof(local)) < 0){
        cerr << "bind err" << endl;
        return 2;
    }

    if (listen(lsock, NUM) < 0){
        cerr << "listen err" << endl;
        return 3;
    }

    struct sockaddr_in peer;
    for(;;){
        socklen_t len = sizeof(peer);
        int sock = accept(lsock, (struct sockaddr*)&peer, &len);
        if (sock < 0){
            cerr << "accept err" << endl;
            continue;
        }
        cout << "get a link : " << sock << endl;
        int *p = new int(sock);
        pthread_t tid;
        pthread_create(&tid, nullptr, Routinue, p);
    }

    return 0;
}
