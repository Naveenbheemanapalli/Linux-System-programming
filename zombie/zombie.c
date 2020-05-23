/*
* zombie.c
*
* This program creates a Zombie process
*
* Author : Bheemanapalli Naveen Kumar, Sasken Technologies
*
* License: MIT
*
*/
#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<unistd.h>

int main(){
	pid_t child_pid=0;
	
	child_pid = fork();
	
	switch(child_pid){
		case -1 : perror("fork");
							exit(EXIT_FAILURE);
							
		case 0 : printf("In the Child process pid_t = %d , ppid_t = %d\n",getpid(),getppid());
							printf("Child going to be Terminated Now\n");
							printf("Child is becoming Zombie NOW\n");
							exit(EXIT_SUCCESS);
							
		default : printf("In the parent process of the pid = %d\n",getpid());
							sleep(10);
							printf("Parent going to be Terminated Now\n");
							exit(EXIT_SUCCESS);
	}
}
