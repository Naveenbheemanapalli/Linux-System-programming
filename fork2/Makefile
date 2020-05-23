#!/bin/bash

CC = gcc 
FLAGS = -Wall -Werror -c 

fork2 : fork2.o fork2.c
	$(CC) fork2.o -o fork2
	
fork2.o : fork2.c
	$(CC) $(FLAGS) fork2.c
	
clean :
	rm *.o fork2
	

