#include <sys/stat.h>
#include <sys/types.h>
#include <dirent.h>
#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <linux/kernel.h>

int main(int argc, char** argv) {

	char charDir[100];
	char path[100];
	char readable;
	char writable;
	char executable;

	// gets the directory name
	int indexOfDir = 1;
	strcpy(charDir, argv[indexOfDir]);


	if (getcwd(path, 100) == NULL) { // gets the current path.
		perror("getcwd() error");
	}
	else {
		strcat(path, "/");
	}

	strcat(path, charDir);

	DIR* dir = opendir(path);
	if (dir) {
		printf("[DIR] {%s} exists!\n", charDir);
		chdir(path);
	}
	else {
		printf("[DIR] {%s} does not exist, CREATE IT\n", charDir);

		printf("\nDo you want to make {%s} readable? [Y/n]: ", charDir);
		scanf(" %c", &readable);

		printf("\nDo you want to make {%s} writable? [Y/n]: ", charDir);
		scanf(" %c", &writable);

		printf("\nDo you want to make {%s} executable for everyone? [Y/n]: ", charDir);
		scanf(" %c", &executable);

		int mode = 0;

		if (readable == 'y' || readable == 'Y') {
			mode += 4;
		}

		if (writable == 'y' || writable == 'Y') {
			mode += 2;
		}

		if (executable == 'y' || executable == 'Y') {
			mode += 1;
		}

		mode += 770;
		int begInt = 0;

		char s1[8];
		char s2[8];
		sprintf(s1, "%d", begInt);
		sprintf(s2, "%d", mode);
		strcat(s1, s2);
		printf("\n%s", s1);
		mode_t old_mask = umask(0);
		long newValue = strtol(s1, 0, 8);
		int dir = mkdir(path, newValue);
		umask(old_mask);
	}




	return 0;
}