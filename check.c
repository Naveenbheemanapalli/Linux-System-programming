#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>

int main(){

pid_t ch_pid;

ch_pid = fork();

switch(ch_pid){
	case -1:
		perror("fork");
		exit(1);
	case 0 :
		while(1){
			printf("C"); sleep(1);}
		break;
	default :
			while(1){
				printf("P");sleep(1);}
		break;


}



}
