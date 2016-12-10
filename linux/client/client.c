#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/un.h>
 
#define DEFAULT_PROTOCOL 0
#define MAXLINE 100
 
readLine(int fd, char* str);
 
int main(){
 
   int sfd, result;
 
   char inmsg[MAXLINE], outmsg[MAXLINE];
   struct sockaddr_un serverAddr;
   
   sfd = socket(AF_UNIX, SOCK_STREAM, 0);
   serverAddr.sun_family = AF_UNIX;
   strcpy(serverAddr.sun_path, "convert");
   
   do{
      result = connect(sfd, (struct sockaddr*)&serverAddr, sizeof(serverAddr));
      if(result == -1)sleep(1);
      
   }while(result == -1);
 
   printf("Name:");
   fgets(inmsg, MAXLINE, stdin);
   write(sfd, inmsg,strlen(inmsg)+1);
   
   readLine(sfd, outmsg);
   printf("%s-->\n%s",inmsg,outmsg);
   close(sfd);
   exit(0);
}
 
readLine(int fd, char* str){
   int temp;
   do{
      temp = read(fd, str, 1);
   }while(temp>0 && *str++!=NULL);
   return(temp>0);
}
