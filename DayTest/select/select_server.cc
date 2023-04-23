#include <iostream>
#include <sys/select.h>
#include <string>
#include "Sock.hpp"

using std::cout;
using std::endl;
using std::string;

#define NUM sizeof(fd_set) * 8

int fd_array[NUM];

static void Usage(string proc)
{
    cout << "Usage : " << proc << " port " << endl;
}

// select_server 8081
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

    // 初始化fd_array
    for (int i = 0; i < NUM; ++i)
    {
        fd_array[i] = -1;
    }

    fd_set rfds;               // 读
    fd_array[0] = listen_sock; // 设置为listen套接字
    // cout << "[套接字来了]" << listen_sock << endl;
    for (;;)
    {
        int max_f = fd_array[0];
        FD_ZERO(&rfds);
        // 把需要关心的fd添加进rfds, -1表示不合法
        for (int i = 0; i < NUM; ++i)
        {
            if (fd_array[i] == -1)
                continue;
            // 到这说明都是合法fd
            FD_SET(fd_array[i], &rfds);
            if (max_f < fd_array[i])
            {
                max_f = fd_array[i]; // 更新最大的fd
            }
        }

        // 5s一次返回，如果有fd了，就不会看时间，会一直提示
        struct timeval timeout = {0, 0};

        int n = select(max_f + 1, &rfds, nullptr, nullptr, nullptr);
        switch (n)
        {
        case -1:
            cout << "select err" << endl;
            break;
        case 0:
            // cout << "select timeout" << endl;
            break;
        default:
            cout << "有fd就绪啦" << endl;
            // 到这就可以read、recv了吗？不可以，要判断有效无效
            for (int i = 0; i < NUM; ++i)
            {
                if (fd_array[i] == -1)
                    continue;
                // 查看是否在集合里
                if (FD_ISSET(fd_array[i], &rfds))
                {
                    cout << "[" << fd_array[i] << "上有读事件就绪了]" << endl;
                    // 到这就可以read、recv了吗？还是不可以哦，要判断套接字还是普通文件
                    if (fd_array[i] == listen_sock)
                    {
                        // 开始accept
                        int sock = Sock::Accept(listen_sock);
                        if (sock >= 0)
                        {
                            cout << "建立新连接" << endl;
                            // 到这就可以read、recv了吗？还还还是不可以，因为不知道有无数据
                            // 怎么知道有无数据，select知道，但是select在前面，无法直接将sock放入rfds
                            // 所以这里就需要用到第三方数组，全局变量fd_array啦
                            // 找到数组中未使用的位置，从1开始，0作为监听套接字
                            int pos = 1;
                            for (; pos < NUM; ++pos)
                            {
                                if (fd_array[pos] == -1)
                                    break;
                            }
                            if (pos < NUM)
                            {
                                // 说明有位置
                                fd_array[pos] = sock;
                                cout << "[sock来了]:" << sock << endl;
                            }
                            else
                            {
                                // 说明服务器满载了，关闭sock
                                close(sock);
                            }
                        }
                    }
                    else
                    {
                        // 普通文件
                        cout << "fd_array[" << i << "]上有读事件就绪了" << endl;
                        char buffer[1024] = {0};
                        ssize_t s = recv(fd_array[i], buffer, sizeof(buffer) - 1, 0);
                        if (s > 0)
                        {
                            buffer[s] = '\0';
                            cout << "[" << fd_array[i] << "]:" << buffer << endl;
                        }
                        else if (s == 0)
                        {
                            // 对端关闭了
                            close(fd_array[i]);
                            cout << "[关闭fd:" << fd_array[i] << "]" << endl;
                            fd_array[i] = -1;
                        }
                        else
                        {
                            // 错误
                            close(fd_array[i]);
                            cout << "[关闭fd:" << fd_array[i] << "]" << endl;
                            fd_array[i] = -1;
                        }
                    }
                }
            }

            break;
        }
    }

    return 0;
}
