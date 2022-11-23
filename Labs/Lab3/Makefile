countLeaps: countLeaps.o isLeap.o
	gcc -ansi -Wall -o countLeaps countLeaps.o isLeap.o

countLeaps.o: countLeaps.c
	gcc -ansi -Wall -c countLeaps.c

isLeap.o: isLeap.c
	gcc -ansi -Wall -c isLeap.c

clean:
	rm countLeaps countLeaps.o isLeap.o
