#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<string.h>

int main(){

while(1){
	printf("Enter IDIOT >>> ");
	char cmd[20];
	scanf("%s",cmd);
	pid_t pid_child;
	pid_t ret;int *status;
	pid_child = fork();	
	if(strcmp(cmd,"q")==0){
		break;
	}
	if(pid_child == 0){
		ret = execlp(cmd,cmd,NULL);
		if(ret == -1){
			perror("execlp");
			exit(EXIT_FAILURE);
		}
	}
	else{
		ret = waitpid(pid_child,&status,NULL);
		if(ret == -1){
			perror("waitpid");
			exit(EXIT_FAILURE);
		}
	}

}
}
