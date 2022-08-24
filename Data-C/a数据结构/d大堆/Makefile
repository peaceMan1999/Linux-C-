Test:Heap.o test.o
	gcc -o $@ $^ -std=c99
Heap.o:Heap.c
	gcc -c Heap.c -std=c99
test.o:test.c
	gcc -c test.c -std=c99

.PHONY:clean
clean:
	rm -f *.o Test
