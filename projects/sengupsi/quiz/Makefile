CFLAGS = -Wall -fpic -coverage -lm -std=c99

all: testme.c
	gcc -o testme testme.c $(CFLAGS)
	-./testme > rtquiz.out 
	echo >> rtquiz.out
	gcov -f -b testme.c >> rtquiz.out
	rm -f testme *.gcda *.gcno
