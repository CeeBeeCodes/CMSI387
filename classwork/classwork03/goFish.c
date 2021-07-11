#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int CheckForSevens(char list[]);
    int GetSum();
    float GetAverage();
    int listOfNumbers[25];
    int userInput;
    int exitValue = -9999;
    int index = 0;
    char stringValues[100];


    do {
         printf("Enter a number or -9999 to complete your entries: ");
         scanf("%d", &userInput);

         if (userInput != exitValue) {
            listOfNumbers[index] = userInput;
            index++;
         }
    }
    while (userInput != exitValue);

         int currentSum = GetSum(listOfNumbers, index);
         printf("Your current sum is: %d\n", currentSum);
         float currentAverage = GetAverage(currentSum, index);
         printf("Your current average is: %.2f\n", currentAverage);

        char list_convertToString[100];
        for (int i = 0; i < index; i++) {
           sprintf(list_convertToString, "%d", listOfNumbers[i]);
           strcat(stringValues, list_convertToString);
        }
        printf("Long string of values: %s:\n ", stringValues);
        printf("You have %d 'SEVENS'.\n", CheckForSevens(stringValues));


    return 0;
}

int CheckForSevens(char list[]) {
    int amountOfSevens = 0;
    for (int i = 0; i < strlen(list); i++) {
        char charToCompare = list[i];
        if (charToCompare == '7') amountOfSevens++;
    }
    return amountOfSevens;
}

float GetAverage(int sum, int size) {
    return (float) sum / size;
}

int GetSum(int list[], int size) {
    int sum = 0;
    for(int i = 0; i < size; i++) {
        sum += list[i];
    }
    return sum;
}

