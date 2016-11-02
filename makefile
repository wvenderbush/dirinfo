GCC = gcc -g

all: main.c
	$(GCC) main.c -o prog

main.c: main.c
	$(GCC) -c main.c

clean:
	rm *.o
	rm *~

run: all
	./prog

debug: all
	gdb prog
