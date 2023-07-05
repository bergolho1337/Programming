#include <iostream>
#include <sys/stat.h>
#include <sys/types.h>

int main (int argc, char *argv[]) {
	char dir_name[50] = "test_folder_to_see_if_the_code_will_work";
	if (mkdir(dir_name, 0777) == -1) {
		printf("Error! Folder '%s' already exists!\n", dir_name);
	}
	else {
		printf("Sucess! Folder '%s' created!\n", dir_name);
	}
	return 0;
}
