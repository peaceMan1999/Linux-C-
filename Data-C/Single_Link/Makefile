SList:SList.o main.o
	gcc -o $@ $^ -std=c99
main.o:main.c
	gcc -c main.c -std=c99
SList.o:SList.c
	gcc -c SList.c -std=c99

.PHONY:clean
clean:
	rm -rf *.o SList


