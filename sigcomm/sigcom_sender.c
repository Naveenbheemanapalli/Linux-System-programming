/*
*
* sigcom_snder.c
*
* This program is used to send a Real time SIGRTMIN signal to another 
* process of the provided pid by the user and the sigqueue is used 
* to send data to another process
*
* Author : Bheemanapalli Naveen Kumar, Sasken Technologies
*
* License: MIT
*/

#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<signal.h>

int main(int argc,char **argv){
	int status=0;
	union sigval val;

	if(argc != 3){
		printf("Usage :- ./sigcom_snder  rx'er_pid  integer_data \n");
		exit(EXIT_FAILURE);
	}	
	
	status = kill(atol(argv[1]),0);
	if(status != 0){
		printf("PID you provided process doesn't exists\n");
		printf("Please provide the reciever PID only Pls\n");
		perror("kill");
		exit(EXIT_FAILURE);
	}
	
	val.sival_int = atoi(argv[2]);
	status = sigqueue(atoi(argv[1]),SIGRTMIN,val);
	if(status == -1){
		perror("sigqueue");
		exit(EXIT_FAILURE);
	}
}







/*
int main(int argc,char **argv){
    int status=0;
    struct sigaction action,old_action;
    struct siginfo_t siginfo;
    siginfo.si_value.sival_int = atoi(argv[2]);

    kill(atoi(argv[1]),SIGRTMIN);





}	
	*/
	/*struct sigaction action,old_action;
	action.sa_sigaction = sig_handler;
	sigemptyset(&action.sa_mask);
	action.sa_flags = SA_SIGINFO | SA_NODEFER | SA_RESTART;
	
	status = sigaction(SIGRTMIN,&action,&old_action);
	if(status == -1){
		perror("sigaction");
		exit(EXIT_FAILURE);
	}*/

