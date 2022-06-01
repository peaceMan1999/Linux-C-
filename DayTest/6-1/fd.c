#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

int main()
{
    
    // c语言函数
    printf("hello printf\n");
    fprintf(stdout, "hello fprintf\n");
    //fputs("hello fputs %d %f %a\n", stdout);
    //fflush(stdout);
    
    const char *msg = "hello write\n";
    // system call
    write(1, msg, strlen(msg));
    
    fork();

    //umask(0);
    //close(1);
    //int fd = open("log.txt", O_WRONLY|O_APPEND);
    //if (fd < 0){
    //    perror("open!");
    //    return 1;
    //}
    //
    //printf("hello printf\n");
    //fprintf(stdout, "hello fprintf\n");
    //fputs("hello fputs\n", stdout);
    //fflush(stdout);
  

    ////close(0)
    //char buf[32];
    //fgets(buf, 32, stdin);
    //printf("%s\n", buf);
    //    

    ////fclose(stdout);
    //close(fd);

    return 0;
}

