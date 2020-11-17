//#include <string>
#include <string.h>
#include <iostream>
#include <experimental/filesystem>

#include <unistd.h>
//#include <fstream>

#define MAXX 10000
#define LEN 100

//namespace fs = std::filesystem;
namespace fs = std::experimental::filesystem;

//const int MAXX 10000;
//const int LEN 100;

int main() {
	std::string str;
	char archive_map[MAXX][LEN];
	size_t len_archive = 0;
	chdir("./archive/maps");
	std::string path = ".";
	//std::string path = "./archive/maps";
	for (const auto & entry : fs::directory_iterator(path)){
		str = entry.path();	// "./name_file"
		
		//Передаем в наш массив name_file и удаляем из начала "./"
		size_t i;
		for (i = 2; str[i] != '\0'; ++i)
			archive_map[len_archive][i - 2] = str[i];
		archive_map[len_archive][i] = '\0';
		
		++len_archive;
	}
	
	return 0;
}
