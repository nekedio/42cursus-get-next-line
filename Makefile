gc:
	gcc -D BUFFER_SIZE=32 get_next_line.c get_next_line_utils.c main.c

gcr:	gc
	./a.out fixtures/ex

gcr1:	gc
	./a.out fixtures/ex1

gcr2:	gc
	./a.out fixtures/ex2

r:
	./a.out
