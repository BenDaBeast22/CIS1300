all: babyQuery babiesQuery

babiesQuery:babiesQuery.c chop.o removeCommas.o
	gcc -ansi -Wall -o babiesQuery babiesQuery.c chop.o removeCommas.o

babyQuery: babyQuery.o chop.o removeCommas.o
	gcc -ansi -Wall -o babyQuery babyQuery.o chop.o removeCommas.o

babyQuery.o: babyQuery.c
	gcc -ansi -Wall -c babyQuery.c

chop.o: chop.c
	gcc -ansi -Wall -c chop.c

removeCommas.o: removeCommas.c
	gcc -ansi -Wall -c removeCommas.c

clean:
	rm babyQuery babiesQuery babyQuery.o chop.o removeCommas.o
