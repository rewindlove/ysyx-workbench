#gcc ex1.c -o ex1
ex1:ex1.o
	gcc ex1.o -o ex1
ex1.o:ex1.s
	gcc -c ex1.s -o ex1.o
ex1.s:ex1.i
	gcc -S ex1.i -o ex1.s
ex1.i:ex1.c
	gcc -E ex1.c -o ex1.i
.PHONY:clean
clean:
	rm *.o *.i *.s
