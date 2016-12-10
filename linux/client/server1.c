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
 
   int sfd, cfd, clientlen;
 
   char inmsg[MAXLINE], outmsg[MAXLINE] = "hi~";
   struct sockaddr_un serverAddr, clientAddr;
 
   signal(SIGCHLD, SIG_IGN);
   clientlen = sizeof(clientAddr);
 
   sfd = socket(AF_UNIX, SOCK_STREAM, 0);
   serverAddr.sun_family = AF_UNIX;
   
   strcpy(serverAddr.sun_path, "convert");
   unlink("convert");
 
   bind(sfd, (struct sockaddr *) &serverAddr, sizeof(serverAddr));
   listen(sfd, 5);
 
   while(1){
      cfd = accept(sfd, (struct sockaddr*)&clientAddr, &clientlen);
      if(fork()==0){
         readLine(cfd, inmsg);
         strcat(outmsg, inmsg);
         write(cfd,outmsg, strlen(outmsg)+1);
         close(cfd);
         exit(0);
      }
      else{
         close(cfd);
      }
   }
}
 
readLine(int fd, char *str){
   int n;
   do{
      n = read(fd, str, 1);
   }while(n>0 && *str++!=NULL);
 
   return(n>0);
}
