#include <stdio.h>
#include <string.h>


void AverageFinder(int array_v[], int size_)
{
    double sum_ = 0;

    printf("Enter %d elements:\n", size_);
    for (int i = 0; i < size_; ++i)
    {
        printf("Element %d: ", i + 1);
        scanf("%d", &array_v[i]);
        sum_ += array_v[i];
    }

    printf("Sum: %.2lf \n", sum_);
    printf("Average: %.2lf \n", sum_ / size_);
}





void take_info()
{
    int age;
    char name[10];
    char address[10];
    char email[15];

    printf("Enter your name: ");
    scanf("%9s", name);

    printf("\nEnter your age: ");
    scanf("%d", &age);

    getchar();

    printf("\nEnter your email: ");
    scanf("%14s", email);

    getchar();

    printf("\nEnter your address: ");
    scanf("%9s", address);

    printf("\n\nName: %s\n", name);
    printf("Age: %d\n", age);
    printf("Email: %s\n", email);
    printf("Address: %s\n", address);
}



void whats_wrong_1()
{
    const char s[8] = "";

    printf("Enter a name : ");
    getchar();
    gets(s);

    strcat(s, " is the best!!");


    printf("\n%s\n",s);

    printf("String size : %d\n",strlen(s));
}


void whats_wrong_2()
{
    char s1[10] = "Network";
    char s2[10] = " Security";
    char s3[20] = "";

    strcat(s3, s1);
    strcat(s3, s2);

    printf("%s\n", s3);

    strncpy(s1, s3, sizeof(s1) - 1);
    s1[sizeof(s1) - 1] = '\0';

    printf("%s\n", s1);
}





int main()
{
    //Task 0 Update the code so that your code follows
    //the first standard, We have discussed.
    int v[10];
    // Task 1: Calculate the average of the 10 array elements
    printf("Task 1: Average of 10 array elements\n");
    AverageFinder(v, 10);

    // Task 2: Scan and print all the information correctly
    printf("\nTask 2: Input and display user information\n");
    take_info();

    // Task 3: Print correct string size
    printf("\nTask 3: Print correct string size\n");
    whats_wrong_1();

     // Task 4: Prevent unnecessary information from being printed
    printf("\nTask 4: Prevent unnecessary information\n");
    whats_wrong_2();

    return 0;
}
