.PHONY:all
all:myproc test

myproc:myproc.c
	gcc -o $@ $^

test:test.c
	gcc -o $@ $^

.PHONY:clean
clean:
	rm -f myproc
