#Pipe
##How To Use pipe
>+ 한프로세스가 파이프를 생성한다
>+ 그 프로세스가 자식 프로세스를 생성한다.
>+ 쓰는 프로세스는 읽기용 파이프 디스크립터는 필요없으므로 닫는다. 읽는 프로세스는 쓰기용 파이프 디스크립터는 필요없으므로 닫는다.
>+ 각 프로세스는 write()와 read() 시스템 콜을 사용하여 파이프를 통해 데이터를 송수신한다.
>+ 각 프로세스가 열려있는 파이프 디스크립터를 닫는다.

##파이프 함수

###popen() 함수
'''

#include<stdio.h>
FILE *popen(const char *command,const char *type);
성공하면 파이프를 위한 파일 포인터를 실패하면 NULL을 반환한다.

int pclose(FILE *fp);
성공하면 command 명령어의 종료 상태를 실패하면 -1을 반환한다.
'''