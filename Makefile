all: *.c
	gcc -g *.c -o main

install:
	sudo cp ./main /usr/bin/bm

clean: main
	rm -f ./main
