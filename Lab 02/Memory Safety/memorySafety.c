#include <stdio.h>
#include <stdlib.h>
int main() {

    char *ptrName;
    char fullName[] = "Md. Ishmam Uddin";

    ptrName = fullName;

    printf("My name is %s\n",ptrName);

    int *ptrSalary = malloc(sizeof(int));
    *ptrSalary = 1000;
    printf("My salary is %d\n",*ptrSalary);
    free(ptrSalary);
    *ptrSalary = 2000;
    printf("After promotion my salary will be %d\n",*ptrSalary);

    char* alphabet = (char*) malloc(27);

    alphabet[26] = '\0';

    for(int i=0;i<26;i++)alphabet[i] = i+'A';
    //char* revAlphabet = alphabet - 26;
    //for(int i=0;i<26;i++)revAlphabet[i] = 'Z'-i;
    //You need to print A-Z
    printf("%s\n",alphabet);

    return 0;
}
