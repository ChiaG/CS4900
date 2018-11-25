CC = gcc
CFLAGS = -Wall -pedantic -lgmp -lm -o

main: main.c ../modules/runtimeLoad.c ../modules/findRoots.c
	${CC} main.c ../modules/runtimeLoad.c ../modules/findRoots.c ${CFLAGS} main

main.o ../modules/runtimeLoad.o ../modules/findRoots.o: All.h

All.h: ../modules/runtimeLoad.h ../modules/findRoots.h
	touch All.h

clean:
	rm -f *.o main

run: main
	./main ${ARGS}
