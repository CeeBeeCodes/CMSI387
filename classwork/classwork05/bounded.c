#include <windows.h>
#include <unistd.h>
#include <stdio.h>


DWORD WINAPI ThreadFunc( LPVOID );

int mutex = 1;
int full = 0;
int empty = 7;
int x = 0;
int n;
double amountOfTimeConsumer;
double amountOfTimeProducer;



int myWait(int s) {
	return (--s);
}

int mySignal(int s) {
	return (++s);
}

DWORD WINAPI producer(void *ignored) {
	while (1) {
    Sleep(amountOfTimeProducer);
    if (mutex == 1 && empty !=0) {
        mutex = myWait(mutex);
	full = mySignal(full);
	empty = myWait(empty);
	x++;
	printf("\n Producer produces the item %d\n", x);
	mutex = mySignal(mutex);
    }
    else printf("\nBuffer is full!!\n");


	}

}

DWORD WINAPI consumer(void *ignored) {
	while (1) {
        Sleep(amountOfTimeConsumer);
        if (mutex == 1 && full !=0 ) {
             mutex = myWait(mutex);
        full = myWait(full);
        empty = mySignal(empty);
        printf("\n Consumer consumes the item %d\n", x);
        x--;
        mutex = mySignal(mutex);
        }
        else printf("\nBuffer is empty!!\n");

	}

}

double ConvertToSeconds(double s) {
    return (double) s * 1000;
}


int main( int argc, char * argv ) {
   HANDLE hThread1;
   HANDLE hThread2;
   DWORD  threadID1;
   DWORD  threadID2;

   printf("Enter amount of time (under 10 seconds) producer produces: ");
   scanf("%lf", &amountOfTimeProducer);
   printf("Enter amount of time (under 10 seconds) consumer consumes: ");
   scanf("%lf", &amountOfTimeConsumer);

   amountOfTimeProducer = ConvertToSeconds(amountOfTimeProducer);
   amountOfTimeConsumer = ConvertToSeconds(amountOfTimeConsumer);


   hThread1 = CreateThread( NULL, 0, producer, (LPVOID)1, 0, &threadID1 );
   hThread2 = CreateThread( NULL, 0, consumer, (LPVOID)2, 0, &threadID2 );

   if (hThread1) printf("\nproducer thread has launched\n");
   if (hThread2) printf("consumer thread has launched\n");

   Sleep(10000);

   printf("Exit Program.");
   TerminateThread(hThread1, threadID1);
   TerminateThread(hThread2, threadID2);



   return EXIT_SUCCESS;

}

