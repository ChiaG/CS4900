CC = gcc

#CFLAGS = -g -Wall -pedantic
CFLAGS = -O -Wall -pedantic
 
main : main.o
	gcc main.c -o main.o -lgmp -lm

clean:
	rm -f *.o core main

run: main
	./main
	

