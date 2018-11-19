CC = gcc
CFLAGS = -Wall -pedantic -lgmp -lm -o

main: main.c ../modules/runtimeLoad.c
	${CC} main.c ../modules/runtimeLoad.c ${CFLAGS} main
clean:
	rm -f *.o main
run: main
	./main ${ARGS}
