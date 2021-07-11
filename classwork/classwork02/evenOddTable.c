#include <stdio.h>
#include <stdlib.h>

int main() {

const char* GetNumberType();
int GetProduct(int value);
int counter = -10;
int oddCounter = 0;
int evenCounter = 0;

while (counter <= 10) {
    int modulus = counter % 2;
    if (modulus == 0) evenCounter++;
    else oddCounter++;

    printf("%d\t %d\t %s\n", counter, GetProduct(counter), GetNumberType(counter));
    counter++;
}
printf("\n# of odd numbers = %d\n# of even numbers = %d\n", oddCounter, evenCounter);
return 0;
}

const char* GetNumberType(int value) {
     int modulus = value % 2;
     if (modulus == 0) return "EVEN";
     else return "ODD";
}

int GetProduct(int value) {
    return value * value;
}
