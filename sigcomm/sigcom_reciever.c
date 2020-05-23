/*
*
* sigcom_rxer.c
*
* This program contains a signal handler function to handle the 
* SIGRTMIN signal and this signal gets the integer data it will be displayed on the screen
* and when -1 comes the process will terminates
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

void sig_handler(int signum,siginfo_t *siginfo,void *args){

	if(siginfo->si_value.sival_int == -1)
			exit(EXIT_SUCCESS);
	printf("Data Recieved from the Sender is :- ");
	printf("%d \n",siginfo->si_value.sival_int);

}


int main(int argc,char **argv){
	int status=0;
	printf("Use the pid:- %d in the Sender section for communication\n",getpid());

	struct sigaction action,old_action;
	action.sa_sigaction = sig_handler;
	sigemptyset(&action.sa_mask);
	action.sa_flags = SA_SIGINFO | SA_NODEFER | SA_RESTART;
	
	status = sigaction(SIGRTMIN,&action,&old_action);
	if(status == -1){
		perror("sigaction");
		exit(EXIT_FAILURE);
	}
	
	for(;;)
        (void)pause();
}
