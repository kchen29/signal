all: signal.o
	gcc signal.o

signal.o: signal.c
	gcc -c signal.c

clean:
	rm -f *.o *~ a.out text.txt

run: all
	./a.out
