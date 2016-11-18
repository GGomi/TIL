#include <stdio.h>
#define MAXLINE 100

/* popen() 함수를 이용해 자식에서 실행되는 명령어 출력을 받아 프린트한다.*/

int main(int argc, char *argv[]) {
  char line[MAXLINE];
  FILE *fpin;

  if((fpin = popen(argv[1],"r"))==NULL){
    perror("popen Error");
    exit(1);
  }
  printf("자식프로세스로부터 받은 결과\n");
  while(fgets(line,MAXLINE,fpin))//파이프에서 명령어 출력 읽기
    fputs(line,stdout);

  pclose(fpin);
  exit(0);
}
