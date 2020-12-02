#include <stddef.h>
#include <stdbool.h>
#include <stdio.h>
#include <dlfcn.h>


typedef void (*hello_message_t)(const char *);
typedef void (*bye_message_t)(const char *, const size_t);

hello_message_t hello_message;
bye_message_t bye_message;

bool init_library() {
	void *lib = dlopen("./libHello.so", RTLD_LAZY);
	if (NULL == lib)
		return false;
	
	hello_message = (hello_message_t) dlsym(lib, "hello_message");
	bye_message = (bye_message_t) dlsym(lib, "bye_message");
	
	if ( NULL == hello_message || NULL == bye_message)
		return false;
	return true;
}


int main(){
	if ( !init_library() ){
		printf("Library was not loaded\n");
		return 0;
	}
		
	hello_message("Bruh");
	hello_message("Bruh");
	bye_message("Bruh", 3);

	return 0;
}
