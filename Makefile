all: *.c
	gcc *.c -o bm

clean: bm
	rm -f ./bm

