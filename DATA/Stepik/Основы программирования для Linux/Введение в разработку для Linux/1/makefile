all: exe lib

run:
	./hello

exe:	hello.h main.c lib
	# gcc main.c -L. -lHello -o hello
	gcc main.c -fPIC -L. -lHello -o hello

lib: 	hello.h hello.c
	# gcc -shared hello.c -o libHello.so
	gcc -shared hello.c -fPIC -o libHello.so

clean:
	rm -f hello libHello.so
