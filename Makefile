flag = -Wextra -Werror -Wall

gc:
	gcc ${flag} -D BUFFER_SIZE=32 get_next_line.c get_next_line_utils.c main.c

gcr:	gc
	./a.out fixtures/ex

gcr1:	gc
	./a.out fixtures/ex1

gcr2:	gc
	./a.out fixtures/ex2

gcr3:	gc
	./a.out fixtures/ex3

gcr4:	gc
	./a.out fixtures/ex4

gcr5:	gc
	./a.out fixtures/ex5

gcrt:	gc
	./a.out fixtures/ex fixtures/ex1 fixtures/ex2 fixtures/ex3 fixtures/ex4 fixtures/ex5

r:
	./a.out
