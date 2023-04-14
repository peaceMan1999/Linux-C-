#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <errno.h>

void SetFcntl(int fd){
  int fl = fcntl(fd, F_GETFL);
  if (fl < 0){
    perror("fcntl");
    return;
  }
  fcntl(fd, F_SETFL, fl | O_NONBLOCK);
}

int main()
{
  SetFcntl(0);
  while (1){
    char buffer[1024];
    ssize_t s = read(0, buffer, sizeof(buffer)-1);
    if (s > 0){
      printf("read success! %d, errno:%d\n",s, errno);
      buffer[s] = 0;
      write(1, buffer, strlen(buffer));
    }else{
      printf("read err! %d, errno:%d\n",s , errno);
    }

    sleep(1);
  }
  printf("over!\n");
  return 0;
}

