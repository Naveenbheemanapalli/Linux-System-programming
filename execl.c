#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<unistd.h>

int main(){
	int ret;
	const char *const args[] = { "vi", "/home/naveen", NULL };
	
	system("ls");
	
	ret = execv("/bin/ls",args);
	
	if(ret == -1){
			printf("vdsjvs");
			perror("execl");
			return 1;
	}

}
