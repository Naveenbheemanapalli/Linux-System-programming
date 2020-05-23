#!/bin/bash

CC = gcc 
FLAGS = -Wall -Werror -c 

all : sigcom_reciever sigcom_sender

sigcom_reciever : sigcom_reciever.o sigcom_reciever.c
	$(CC) sigcom_reciever.o -o sigcom_reciever

sigcom_reciever.o : sigcom_reciever.c
	$(CC) $(FLAGS) sigcom_reciever.c 
	
sigcom_sender : sigcom_sender.o sigcom_sender.c
	$(CC) sigcom_sender.o -o sigcom_sender
	
sigcom_sender.o : sigcom_sender.c
	$(CC) $(FLAGS) sigcom_sender.c 

clean :
	rm *.o sigcom_reciever sigcom_sender
