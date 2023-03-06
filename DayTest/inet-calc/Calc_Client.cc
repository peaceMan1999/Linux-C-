#include "Protocal.hpp"
#include "Sock.hpp"

void Usage(string msg)
{
    std::cout << "Usage : \n\t" << msg.c_str() << " ip / port" << std::endl;
}

int main(int argc, char *argv[])
{
    if (argc != 3)
    {
        Usage(argv[0]);
        exit(1);
    }

    int sock = Sock::Socket();
    Sock::Connect(sock, argv[1], atoi(argv[2]));

    // 业务逻辑
    request_t req;
    memset(&req, 0, sizeof(req));
    // 写入
    cout << "One : ";
    cin >> req.x;
    cout << "Two : ";
    cin >> req.y;
    cout << "OP : ";
    cin >> req.op;

    // write(sock, &req, sizeof(req));
    // 序列化
    string out = RequestSerialization(req);
    write(sock, out.c_str(), out.size());

    respone_t resp;
    
    // ssize_t s = read(sock, &resp, sizeof(resp));
    char buffer[1024];
    ssize_t s = read(sock, buffer, sizeof(buffer)-1);
    if (s > 0)
    {
        buffer[s] = 0;
        string in = buffer;
        ResponeDeserialization(resp, in);
        // 完整
        cout << "code : " << resp.code << " result : " << resp.result << endl;
    }

    return 0;
}
