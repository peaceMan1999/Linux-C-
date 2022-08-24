Test:SeqList.o test.o
	gcc -o $@ $^ -std=c99
SeqList.o:SeqList.c
	gcc -c SeqList.c -std=c99
test.o:test.c
	gcc -c test.c -std=c99

.PHONY:clean
clean:
	rm -f *.o Test
