#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#define MAXLINE 100
/*
*/
/* 파이프를 통해 자식에서 실행되는 명령어 출력을받아 프린트한다. */

int main(int argc, char* argv[])
{
  int n, pid, fd[2];//fd[0] 읽는부분
  char line[MAXLINE];

  pipe(fd);

  if((pid = fork())==0){
    close(fd[0]);

    dup2(fd[1],1);
    close(fd);
    printf("Hello! pipe\n");
    printf("Bye! pipe\n");
  } else {
    close(fd[1]);
    printf("자식 프로세스로부터 받은 결과\n");
    while((n = read(fd[0],line,MAXLINE)) > 0){
      write(STDOUT_FILENO,line,n);
    }
  }
  exit(0);
}
