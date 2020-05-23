
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
		exit(1);
	}	
	
	val.sival_int = atoi(argv[2]);
	status = sigqueue(atoi(argv[1]),SIGRTMIN,val);
    if(status != 0){
        exit(1);
    }
}







