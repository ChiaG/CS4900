CC = gcc
CFLAGS = -Wall -pedantic -lgmp -lm -o

main: main.c
	${CC} main.c ${CFLAGS} main
clean:
	rm -f *.o main
run: main
	./main ${ARGS}