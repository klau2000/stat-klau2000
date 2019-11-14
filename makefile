all: stat.o
	gcc -o output stat.o

stat.o: stat.c
	gcc -c stat.c

run:
	./output

clean:
	rm *.o
	rm *~
