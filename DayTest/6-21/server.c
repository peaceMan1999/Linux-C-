#include "comm.h"

int main()
{
    if (mkfifo(FILE_NAME, 0644) < 0){
        perror("mkpipo");
        return 1;
    }

    int fd = open(FILE_NAME, O_RDONLY);
    if (fd < 0){
        perror("open");
        return 2;
    }
   
    int out = open("test-copy.txt", O_CREAT | O_WRONLY, 0644);

   char msg[128];
   while (1){
        msg[0] = 0;
        ssize_t s = read(fd, msg, sizeof(msg)-1);
        if (s > 0){
            write (out, msg, s);
        }
        else{
            break;
        }
       // if (s > 0){
       //     msg[s] = '\0';
       //     printf("client say : %s\n", msg);
       // }
       // else if (s == 0){
       //     printf("end!\n");
       //     break;
       // }
       // else{
       //     break;
       // }
   }

    return 0;
}


