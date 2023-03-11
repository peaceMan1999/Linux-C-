#include "Sock.hpp"
#include <pthread.h>
#include <sys/stat.h>
#include <fstream>

#define WWWROOT "./wwwroot/"
#define HOME_PAGE "index.html"

int i = 1;

void Usage(string proc)
{
    cout << proc.c_str() << " : port " << endl;
}

void *Handler (void* parm)
{
    int sock = *(int*)parm;
    delete (int*)parm;
    // 线程分离
    pthread_detach(pthread_self());

    char buffer[1024*10];
    memset(buffer, 0, sizeof(buffer));

    ssize_t s = recv(sock, buffer, sizeof(buffer), 0);
    // ssize_t s = read(sock, buffer, sizeof(buffer)-1);
   
    if (s > 0){
        buffer[s] = 0;
        cout << buffer << endl;

        string html_file = WWWROOT;
        html_file += HOME_PAGE;

        struct stat st;
        stat(html_file.c_str(), &st);

        // 重定向
        // string response = "http/1.1 301 Permanently moved\n";
        // response += "Location: https:www.qq.com/";
        // response += "\n";
        // send(sock, response.c_str(), response.size(), 0);


        ifstream in(html_file);
        if (in.is_open()){
            // 打开成功
            // cout << "read html" << endl;
            // 仅起区分作用
            cout << "----" << i++  << "-----" << endl;
            
            string http_response = "http/1.0 200 OK\n";
            http_response += "Content-Type:text/html; charset=utf8\n";
            http_response += "Content-Length : ";
            http_response += to_string(st.st_size);
            http_response += "\n";
            http_response += "Set-Cookie : id = 111\n";
            http_response += "Set-Cookie : pwd = qwer\n";

            http_response += "\n"; // 空行

            // http_response += "hello yz!\n";
            string content, line;
            while (getline(in, line)){
                content += line;
            }
            http_response += content;

            in.close();

            send(sock, http_response.c_str(), http_response.size(), 0);
            cout << http_response << endl;
            // cout << "read html end" << endl;
        }else{
            // 打开失败
            string http_response = "http/1.0 404 NO FOUND\n";
            http_response += "Content-Type:text/html; charset=utf8\n";
            http_response += "\n";
            http_response += "<html><p>你访问的资源不存在</p></html>";
            send(sock, http_response.c_str(), http_response.size(), 0);
        }

    }
    close(sock);
    return nullptr;
}

int main(int argc, char *argv[])
{
    // port
    if (argc != 2){
        Usage(argv[0]);
        exit(1);
    }

    uint16_t port = atoi(argv[1]);
    int listen_sock = Sock::Socket();
    Sock::Bind(listen_sock, port);
    Sock::Listen(listen_sock);

    for (;;)
    {
        // cout << "hi" << endl;
        int sock = Sock::Accept(listen_sock);
        // cout << "sock : " << sock << endl;
        if (sock > 0){
            sleep(1);

            pthread_t tid;
            int *parm = new int(sock);
            pthread_create(&tid, nullptr, Handler, parm);
        }
    }

    return 0;
}
