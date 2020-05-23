/*
* fork2.c
*
* This program will creates 2 child processes and the childs are 
* terminated and the parent is waiting for the child via the 
* use of signal handling by handling the SIGCHLD signal
*
* Author : Bheemanapalli Naveen Kumar, Sasken Technologies
*
* License: MIT
*/

#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<unistd.h>
#include<signal.h>
#include<string.h>

void child_handler(int signum,siginfo_t *siginfo,void *args){
	pid_t zom_pid;
	int status=0;
	//printf("PID = %d \n",getpid());	
	
	zom_pid = waitpid(-1,&status,WNOHANG);
	if(zom_pid != -1){
		printf(" Zombie Cleared with pid = %d\n\n",zom_pid);
	}
}

int main(){
	int ret = 0;
	pid_t child_pid_1 = 0,child_pid_2=0;
	//signal(SIGCHLD,child_handler);
	
	struct sigaction action;
	action.sa_sigaction = child_handler;
	action.sa_flags = SA_RESTART | SA_SIGINFO | SA_NODEFER;
	
	ret = sigaction(SIGCHLD,&action,0);
	if(ret == -1){
		perror("sigaction");
		exit(EXIT_FAILURE);
	}
		
	child_pid_1 = fork();
	switch(child_pid_1){
		case -1 : perror("fork");
     			exit(EXIT_FAILURE);
			
		case 0 : printf("In 1st Child process of pid = %d\n",getpid());
				sleep(10);
				printf("1st Child process is going to Terminate Now\n");
				exit(EXIT_SUCCESS);
							
		default : child_pid_2 = fork();
				switch(child_pid_2){
					case -1 : perror("fork");
							  exit(EXIT_FAILURE);
							  
					case 0  : printf("In 2nd Child process of pid = %d\n",getpid());
								sleep(15);
								printf("2nd Child process is going to Terminate Now\n");					 	
								exit(EXIT_SUCCESS);
					default : pause();
						 
				 }			
        pause();
	}
	printf("All Children are Dead, and Parent is Terminating...\n");
}
