#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>


struct Thread {
        char threadLetter;
        int millisecondsToRun;
    }; 
    
static void *child(void* thread) {

struct Thread *t = (struct Thread*)thread;
int totalDuration = t->millisecondsToRun;
float remaining = totalDuration;
float timeElapsed = 0;

while (remaining > 0) {
	sleep(.04);	
	if (remaining <= 40) {
		timeElapsed = remaining;
		printf("%c:%.f:done\n", t->threadLetter, timeElapsed);
		break;
	}
	else {
	timeElapsed = 40;
	remaining -= timeElapsed;
	printf("%c:%.f:%.f\n", t->threadLetter, timeElapsed, remaining);
	} 	
		
}


return 0;
} 

int main(int argc, char *argv[]) {

pthread_t child1thread;
pthread_t child2thread;
pthread_t child3thread;
pthread_t child4thread;

pthread_t *pChildThreads[] = {&child1thread, &child2thread, &child3thread, &child4thread};

struct Thread threads[4];

int t;
int argIndex = 1;
for (t = 0; t < 4; t++) {

threads[t].threadLetter = *argv[argIndex];
threads[t].millisecondsToRun = atoi(argv[argIndex+1]);

pthread_create(pChildThreads[t], NULL, child, (void*) &threads[t]);

argIndex+=2;
}

pthread_exit(NULL);
return 0;

}
