#include<unistd.h>
#include<stdio.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<sys/stat.h>
#include<stdlib.h>
#include<fcntl.h>
#include<linux/fs.h>
int main(){
	pid_t pid;
	int i;
	
	pid = fork();
	if(pid == -1)
		return -1;
	else if(pid != 0)
		exit(EXIT_SUCCESS);

	if(setsid() == -1)
		return -1;
		
	if(chdir("/")==-1)
		return -1;
	
	int max_fd = sysconf(_SC_OPEN_MAX);
	for(i=0;i<max_fd;i++)
		close(i);
		
	open("/dev/null",O_RDWR);
	dup(0);
	dup(0);
	
	return 0;
}
