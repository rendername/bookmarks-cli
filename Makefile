all: main.c command.c add.c storage.c
	gcc main.c command.c add.c storage.c -o main

clean: main
	rm -f ./main

