seqlist:seqlist.o main.o
	gcc -o seqlist seqlist.o main.o -std=c99
seqlist.o:seqlist.c
	gcc -c seqlist.c -std=c99
main.o:main.c
	gcc -c main.c -std=c99

.PHONY:clean
clean:
	rm -rf *.o seqlist

