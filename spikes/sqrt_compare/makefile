CC = gcc
CFLAGS = -Wall -pedantic -lgmp -lm -o

main: main.c
	${CC} main.c ${CFLAGS} main

main.o ../../modules/runtimeLoad.o: ../../main/all.h

../../main/all.h: ../../modules/runtimeLoad.h ../../modules/findRoots.h
	touch ../../main/all.h

clean:
	rm -f *.o main

run: main
	./main
