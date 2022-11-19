LIBS = -lgmp

fib: fib.c
	cc fib.c -o fib $(LIBS) -O2
