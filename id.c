#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
int main(){
	printf("USER ID = %d",getuid());
	printf("group ID = %d",getgid());

}
