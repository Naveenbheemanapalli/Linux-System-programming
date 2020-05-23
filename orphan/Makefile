#!/bin/bash

CC = gcc 
FLAGS = -Wall -Werror -Wextra -c 

orphan : orphan.o orphan.c
	$(CC) orphan.o -o orphan
	
orphan.o : orphan.c
	$(CC) $(FLAGS) orphan.c
	
clean :
	rm *.o orphan
	

