#include "comm.h"

int main()
{
    int fd = open(FILE_NAME, O_WRONLY);
    if (fd < 0){
        perror("open");
        return 2;
    }

    int in = open("test.txt", O_RDONLY);

    char msg[128];
    dup2(in, 0);
    while (1){
        msg[0] = 0;
       // printf("please enter:");
       // fflush(stdout);
        ssize_t s = read(0, msg, sizeof(msg));
        if (s == sizeof(msg)){
            msg[s-1] = 0;
            write(fd, msg, s);
        }
        else if (s > 0){
            write(fd, msg, s);
            printf("copy finish!\n");
            break;
        }
        
    }
    
    close(fd);

    return 0;
}
