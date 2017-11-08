all: signal.o
	gcc signal.o

signal.o: signal.c
	gcc -c signal.c

clean:
	rm -rf *.o *~ a.out

run:
	./a.out
