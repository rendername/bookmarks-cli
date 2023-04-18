all: *.c
	gcc -g *.c -l ncurses -o main

clean: main
	rm -f ./main
