SList:SList.o main.o
	gcc -o $@-d -g $^ -std=c99
main.o:main.c
	gcc -c main.c -g -std=c99
SList.o:SList.c
	gcc -c SList.c -g -std=c99

.PHONY:clean
clean:
	rm -rf *.o SList-d


