#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>


int main()
{
    close(1);
    int fd = open("log.txt", O_WRONLY|O_CREAT, 0666);
    
    printf("fd : %d\n", fd);
    printf("s\n");
    fflush(stderr);
    close(fd);

    //close(1);
    //close(2);
    //int fd = open("log.txt", O_RDONLY);
   // if (fd < 0){
        //error
  //  }

   // printf("fd : %d\n", fd);
   // close(fd);
    
    //int fd = open("log.txt", O_RDONLY);
    //if (fd < 0){
    //    //error
    //}
    //printf("fd : %d\n", fd);
    //close(fd);


    //char buf[32];
    //ssize_t s = read(0, buf, sizeof(buf));
    //if(s > 0){
    //    buf[s] = 0;
    //    write(1, buf, strlen(buf));
    //    write(2, buf, strlen(buf));
    //}
    //return 0;

   // umask(0);
   // int fd = open("log.txt", O_WRONLY|O_CREAT, 0666);
   // if (fd < 0){
   //     perror("open\n");
   //     return 0;
   // }
   // //FILE *fp = fopen("log.txt", "r");
   // //if (NULL == fp){
   // //    perror("fopen\n");
   // //    return 1;
   // //}
   // 
   // char *msg = "hello Linux\n";
   // int s = 5;
   // while(s--){
   //     write(fd, msg, strlen(msg));
   // }

   // //int ret = 5;
   // //while(ret){
   // //    fputs("hello\n", stderr);
   // //    ret--;
   // //}

   // close(fd);

    //int fd1 = open("log.txt", O_WRONLY|O_CREAT, 0666);
    //printf("%d ", fd1);
    //int fd2 = open("log.txt", O_WRONLY|O_CREAT, 0666);
    //printf("%d ", fd2);
    //int fd3 = open("log.txt", O_WRONLY|O_CREAT, 0666);
    //printf("%d ", fd3);
    //int fd4 = open("log.txt", O_WRONLY|O_CREAT, 0666);
    //printf("%d ", fd4);
    //umask(0);
    //int fd = open("log.txt", O_WRONLY|O_CREAT, 0666);
    //if (fd < 0){
    //    perror("open\n");
    //    return 1;
    //}

    //char c;
    //while (1){
    //    ssize_t ret = read(1, &c, 1);
    //    if (ret <= 0){
    //        break;
    //    }
    //    write(1, &c, 1);
    //}

    //close(fd);

    //umask(0);
    //int fd = open("log.txt", O_WRONLY|O_CREAT, 0666);
    //if (fd < 0){
    //    perror("open\n");
    //    return 1;
    //}

    //char *msg = "hello\n";
    //int ct = 5;
    //while (ct--){
    //    write(fd, msg, strlen(msg));
    //}

    //while(1){

    //}
    //close(fd);
    


   // FILE* fp = fopen("log.txt", "r");
   // if (NULL == fp){
   //     printf("fopen error!\n");
   //     return 1;
   // }
   // 
   // char buffer[64];
   //// char *arr = "hello\n";
   // int count = 5;
   // while(count){
   //     //fputs("Linux\n", fp);
   //     fgets(buffer, sizeof(buffer), fp);

   //     printf(buffer);
   //     count--;
   // }

   // fclose(fp);


        

    return 0;
}
