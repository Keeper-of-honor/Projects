all: exe lib

run:
	./hello

exe:	main.c lib
	# gcc main.c -ldl -o hello
	gcc main.c -fPIC -ldl -o hello

lib: 	hello.c
	# gcc -shared hello.c -o libHello.so
	gcc -shared hello.c -fPIC -o libHello.so

clean:
	rm -f hello libHello.so
