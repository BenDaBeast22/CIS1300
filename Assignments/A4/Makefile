all: cgol dynCGOL

cgol: cgol.c chop.o
	gcc -ansi -Wall -o cgol cgol.c chop.o

dynCGOL: dynCGOL.c chop.o
	gcc -ansi -Wall -o dynCGOL dynCGOL.c chop.o

chop.o: chop.c
	gcc -ansi -Wall -c chop.c

clean:
	rm cgol dynCGOL chop.o
