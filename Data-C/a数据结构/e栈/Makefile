Test:Stack.o test.o
	gcc -o $@ $^ -std=c99
Stack.o:Stack.c
	gcc -c Stack.c -std=c99
test.o:test.c
	gcc -c test.c -std=c99

.PHONY:clean
clean:
	rm -f *.o Test
