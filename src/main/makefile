CC = gcc
CFLAGS = -Wall -pedantic -lgmp -lm -o

main: main.c ../modules/runtimeLoad.c ../modules/findRoots.c
	${CC} main.c ../modules/runtimeLoad.c ../modules/findRoots.c ${CFLAGS} main
clean:
	rm -f *.o main
run: main
	./main ${ARGS}
