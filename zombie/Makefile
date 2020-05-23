#!/bin/bash

CC = gcc 
FLAGS = -Wall -Werror -Wextra -c 

zombie : zombie.o zombie.c
	$(CC) zombie.o -o zombie
	
zombie.o : zombie.c
	$(CC) $(FLAGS) zombie.c
	
clean :
	rm *.o zombie
	

