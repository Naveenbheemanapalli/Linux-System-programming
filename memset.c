#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sched.h>
#include<sys/types.h>
#include<sys/wait.h>

int main(){
	struct sched_param sp;
	int policy,max,ret;
	
	policy = sched_getscheduler(0);
	if(policy == -1){
		perror("sched_getscheduler");
		return -1;
	}
	if(policy == SCHED_OTHER)
		printf("CFQ Scheduler used");
	printf("%d\n\n",policy);

	max = sched_get_priority_max(policy);
	if(max == -1){
		perror("sched_get_priority_max");
		return -1;
	}

	printf("%d\n\n\n",max);
}
