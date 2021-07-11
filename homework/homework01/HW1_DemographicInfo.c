#include <stdio.h>
#include <stdlib.h>

int main() {
struct Student_Info {
    char name[30];
    char age[10];
    char classYear[10];
    char gpa[10];
    char major[30];
    char minor[30];
};

struct Student_Info student;

printf("Student Information\n\n");

printf("Enter your full name: ");
fgets(student.name, sizeof student.name, stdin);
sscanf(student.name, "%[^\n]", student.name);
system("cls");


printf("Enter your age: ");
fgets(student.age, sizeof student.age, stdin);
sscanf(student.age, "%s", &student.age);
system("cls");

printf("Enter your class year: ");
fgets(student.classYear, sizeof student.classYear, stdin);
sscanf(student.classYear, "%s", &student.classYear);
system("cls");

printf("Enter your GPA: ");
fgets(student.gpa, sizeof student.gpa, stdin);
sscanf(student.gpa, "%s", &student.gpa);
system("cls");

printf("Enter your major: ");
fgets(student.major, sizeof student.major, stdin);
sscanf(student.major, "%[^\n]", student.major);
system("cls");

printf("Enter your minor: ");
fgets(student.minor, sizeof student.minor, stdin);
sscanf(student.minor, "%[^\n]", student.minor);
system("cls");

printf("Full Name: %s\nAge: %s\nClass Year: %s\nGPA: %s\nMajor: %s\nMinor: %s\n",
       student.name, student.age, student.classYear, student.gpa, student.major, student.minor);

return 0;
}

