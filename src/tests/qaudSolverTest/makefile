CC = gcc
CFLAGS = -Wall -pedantic -lgmp -lm -o

main: main.c ../../modules/findRoots.c
	${CC} main.c ../../modules/findRoots.c ${CFLAGS} main

main.o ../../modules/findRoots.o: ../../main/All.h

../main/All.h: ../../modules/findRoots.h
	touch ../../main/All.h

clean:
	rm -f *.o main

run: main
	./main < input.txt > ../logs/inputTestErrorLog.txt
