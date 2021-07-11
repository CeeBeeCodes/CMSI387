#include <pthread.h>
#include <stdio.h>
#include <unistd.h>


static void* child(void* ignored) {
	while (1) {
		sleep(5);
		printf("Child is awake! Now I go to sleep.\n");
	}

	return 0;
}


int main(int argc, char* argv[]) {
	int enterPressed;
	char ch;

	enterPressed = 0;
	pthread_t child_thread;
	int code;
	code = pthread_create(&child_thread, NULL, child, NULL);
	if (code) {
		fprintf(stderr, "pthread_create failed with code %d\n", code);
	}

	printf("Press 'Enter' to terminate child.\n");
	while (enterPressed != 1) {
		ch = fgetc(stdin);
		if (ch == 0x0A) {
			printf("ENTER KEY IS PRESSED, terminate child.\n");
			pthread_cancel(child_thread);
			enterPressed = 1;
		}
	}


	printf("Program is done.\n");
	return 0;
}