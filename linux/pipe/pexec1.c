#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#define MAXLINE 100
/*
*                 11_18_
*/

/*파이프를 통해 자식에서 실행되는 명령어 출력을 받아 프린트*/

int main(int argc, char* argv[])
{
  int n, pid, fd[2];
  char line[MAXLINE];

  pipe(fd); //파이프 생성

  if((pid = fork())==0){/*자식프로세스*/
    close(fd[0]); //입력닫기
    dup2(fd[1],1);  //표준출력으로 fd복사
    close(fd[1]);
    execvp(argv[1],&argv[1]); //실행

  } else {
    close(fd[1]);
    printf("자식 프로세스로부터 받은 결과\n");
    while((n = read(fd[0],line,MAXLINE)) > 0)
      write(STDOUT_FILENO,line,n);
  }
  exit(0);
}
