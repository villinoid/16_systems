all:
	gcc -o processor processor.c
	gcc -o console console.c
run:
	./processor &
	./console