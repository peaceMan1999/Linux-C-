proc:main.o proc.o
	gcc -o proc main.o proc.o
main.o:main.c
	gcc -c main.c
proc.o:proc.c
	gcc -c proc.c

.PHONY:clean
clean:
	rm -f *.o proc

