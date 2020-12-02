all: exe lib

run:
	./out

exe:	main.c solution.h lib
	gcc -Wall -Wextra -g main.c -fPIC -L. -lsolution -o out

lib:	solution.h solution.c
	gcc -shared solution.c -fPIC -o libsolution.so

clean:
	rm out libsolution.so
