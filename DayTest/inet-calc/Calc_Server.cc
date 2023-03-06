#include "Protocal.hpp"
#include "Sock.hpp"
#include <pthread.h>

void *Hander(void *pram)
{
    int sock = *(int *)pram;
    delete (int *)pram;

    // 线程分离
    pthread_detach(pthread_self());

    request_t req;
    // ssize_t s = read(sock, &req, sizeof(req));
    char buffer[1024];
    ssize_t s = read(sock, buffer, sizeof(buffer)-1);
    // 1、读取 2、分析 计算 3、返回 4、结束
    // 1、短服务
    // if (s == sizeof(req))
    if (s > 0)
    {
        // 完整性
        buffer[s] = 0;
        string str = buffer;

        // 反序列化 
        RequestDeserialization(req, str);

        respone_t resp;
        memset(&resp, 0, sizeof(resp));
        switch (req.op)
        {
        case '+':
            resp.result = req.x + req.y;
            break;
        case '-':
            resp.result = req.x - req.y;
            break;
        case '*':
            resp.result = req.x * req.y;
            break;
        case '/':
            if (req.y == 0){
                resp.code = -1;
            }else{
                resp.result = req.x / req.y;
            }
            break;
        case '%':
            if (req.y == 0){
                resp.code = -2;
            }else{
                resp.result = (req.x % req.y);
            }
            break;
        default:
            resp.code = -3;
            break;
        }

        //write(sock, &resp, sizeof(resp)); // 写入
        // 序列化
        string out = ResponeSerialization(resp);
        write(sock, out.c_str(), out.size());
        cout << "服务结束" << endl;
    }

    // 总是关闭
    close(sock);
}

void Usage(string msg)
{
    std::cout << "Usage : \n\t" << msg.c_str() << " port" << std::endl;
}

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        Usage(argv[0]);
        exit(1);
    }

    uint16_t port = (uint16_t)atoi(argv[1]);

    int listen_sock = Sock::Socket();
    Sock::Bind(listen_sock, port);
    Sock::Listen(listen_sock);

    for (;;)
    {
        int sock = Sock::Accept(listen_sock);
        if (sock >= 0)
        {
            cout << "get a new client.." << endl;
            int *pram = new int(sock);
            pthread_t tid;
            pthread_create(&tid, nullptr, Hander, pram);
        }
    }

    return 0;
}
