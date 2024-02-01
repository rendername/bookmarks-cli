all: *.c
	gcc -g *.c -l ncurses -o main

install:
	sudo cp ./main /usr/bin/bm

clean: main
	rm -f ./main
