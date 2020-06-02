#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>
#include<sys/uio.h>
int main(){

	struct iovec iov[3];
	char buf1[50],buf2[50],buf3[50];
	
	int fd,i;
	
	fd = open("vect_write.txt",O_RDONLY);
	if(fd == -1){
		perror("open");
		return 1;
	}

	iov[0].iov_base = buf1;
	iov[0].iov_len = sizeof(buf1);
	iov[1].iov_base = buf2;
	iov[1].iov_len = sizeof(buf2);
	iov[2].iov_base = buf3;
	iov[2].iov_len = sizeof(buf3);
	
	i = readv(fd,iov,3);
	
	if(i == -1){
	perror("readv");
	return 1;
	}
	
	printf("%s",(char *)iov[0].iov_base);

}
