CC = gcc
CFLAGS = -Wall -pedantic -lgmp -lm -o

main: main.c ../../modules/runtimeLoad.c
	${CC} main.c ../../modules/runtimeLoad.c ${CFLAGS} main

main.o ../../modules/runtimeLoad.o: ../../main/All.h

../main/All.h: ../../modules/runtimeLoad.h
	touch ../../main/All.h

clean:
	rm -f *.o main

run: main
	./main < input.txt > ../logs/inputTestErrorLog.txt
