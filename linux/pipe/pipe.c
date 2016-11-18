#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#define MAXLINE 100

/* 파이프를 통해 자식에서 부모로 데이터를 보내는 프로그램 */
int main()
{
  int n,length,fd[2];
  int pid;

  char message[MAXLINE], line[MAXLINE];

  pipe(fd);

  if(pid = fork() == 0){
    close(fd[0]);
    sprintf(message,"Hello from PID %d\n",getpid());
    length = strlen(message)+1;
    write(fd[1],message,length);
  } else {
    close(fd[1]);
    n = read(fd[0], line, MAXLINE);
    printf("[%d] %s",getpid(),line);
  }
  exit(0);
}
