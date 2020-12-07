flag = -Wextra -Werror -Wall

gcc:
	gcc ${flag} -D BUFFER_SIZE=32 get_next_line.c get_next_line_utils.c main.c

gccr:	gcc
	./a.out fixtures/ex

gccr1:	gcc
	./a.out fixtures/ex1

gccr2:	gcc
	./a.out fixtures/ex2

gccr3:	gcc
	./a.out fixtures/ex3

gccr4:	gcc
	./a.out fixtures/ex4

gccr5:	gcc
	./a.out fixtures/ex5

gccr6:	gcc
	./a.out fixtures/ex6

gccr7:	gcc
	./a.out fixtures/ex7

gccrt:	gcc
	./a.out fixtures/ex fixtures/ex1 fixtures/ex2 fixtures/ex3 fixtures/ex4 fixtures/ex5

run:
	./a.out
