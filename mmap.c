#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>
#include<sys/mman.h>

int main(int argc,char *argv[]){
	int fd;
	char *ptr;
	struct stat sb;
	int nr;
	fd = open("vect_write.txt",O_RDONLY);
	if(fd == -1){
		perror("open");
		return 1;
	}
	
	nr = fstat(fd,&sb);
	if(nr == -1){
		perror("fstat");
		return 1;
	}
	
	ptr = mmap(0,sb.st_size,PROT_READ,MAP_SHARED,fd,0);
	if(ptr == MAP_FAILED){
		perror("mmap");
		return 1;
	}
	
	close(fd);
	off_t len;
	for(len =0 ;len < sb.st_size;len++){
			putchar(ptr[len]);
	}
	
	

}
