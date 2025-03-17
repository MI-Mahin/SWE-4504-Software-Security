#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {

    char fullName[] = "Md. Ishmam Uddin";
    char *ptrName = fullName; //fixed
    printf("My name is %s\n",ptrName);

    int *ptrSalary = (int*)malloc(sizeof(int));
    *ptrSalary = 1000; //fixed
    printf("My salary is %d\n",*ptrSalary);
    
    free(ptrSalary);
    ptrSalary = NULL; //fixed
    
    ptrSalary = (int*)malloc(sizeof(int)); //fixed
    *ptrSalary = 2000; 
    printf("After promotion my salary will be %d\n",*ptrSalary);
    free(ptrSalary);
    ptrSalary = NULL;

    char* alphabet = (char*) malloc(27); //fixed
    for (int i = 0; i < 26; i++) {
        alphabet[i] = 'A' + i;
    }
    alphabet[26] = '\0'; // fixed
    
    char *revAlphabet = (char*)malloc(27);
    for (int i = 0; i < 26; i++) {
        revAlphabet[i] = 'Z' - i;
    }
    revAlphabet[26] = '\0'; // fixed

    printf("A-Z: %s\n", alphabet); //fixed

    return 0;
}