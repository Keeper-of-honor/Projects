all: exe lib

exe:	main.c hello.h lib
	gcc main.c -L. -lHello -o out

lib:	hello.c hello.h
	gcc -shared hello.c -o libHello.so

clean:	out libHello.so
	rm out libHello.so 
