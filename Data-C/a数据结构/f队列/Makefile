Test:Queue.o test.o
	gcc -o $@ $^ -std=c99
Queue.o:Queue.c
	gcc -c Queue.c -std=c99
test.o:test.c
	gcc -c test.c -std=c99

.PHONY:clean
clean:
	rm -f *.o Test
