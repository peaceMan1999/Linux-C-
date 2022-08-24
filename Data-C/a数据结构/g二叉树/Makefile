Test:Tree.o test.o
	gcc -o $@ $^ -std=c99
Tree.o:Tree.c
	gcc -c Tree.c -std=c99
test.o:test.c
	gcc -c test.c -std=c99

.PHONY:clean
clean:
	rm -f *.o Test
