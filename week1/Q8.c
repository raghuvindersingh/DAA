#include<stdio.h>
struct Student {
    int roll;
    char name[50];
    int marks[5];
    int total;
    float percentage;
    char grade;
};

int main() {
    struct Student s[100];
    int n, i, j, topper = 0;
    float average, sum = 0;
    printf("Enter number of students: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        printf("\nEnter details of student %d:\n", i + 1);
        printf("Roll number: ");
        scanf("%d", &s[i].roll);
        printf("Name: ");
        scanf("%s", s[i].name);
        s[i].total = 0;
        printf("Enter marks of 5 subjects: ");
        for (j = 0; j < 5; j++) {
            scanf("%d", &s[i].marks[j]);
            s[i].total = s[i].total + s[i].marks[j];
        }

        s[i].percentage = s[i].total / 5.0;
        if (s[i].percentage >= 90)
            s[i].grade = 'A';
        else if (s[i].percentage >= 75)
            s[i].grade = 'B';
        else if (s[i].percentage >= 60)
            s[i].grade = 'C';
        else if (s[i].percentage >= 40)
            s[i].grade = 'D';
        else
            s[i].grade = 'F';
        sum = sum + s[i].percentage;
        if (s[i].total > s[topper].total)
            topper = i;
    }

    printf("\n--- Student Results ---\n");
    for (i = 0; i < n; i++) {
        printf("\nRoll: %d", s[i].roll);
        printf("\nName: %s", s[i].name);
        printf("\nTotal: %d", s[i].total);
        printf("\nPercentage: %.2f", s[i].percentage);
        printf("\nGrade: %c\n", s[i].grade);
    }
    printf("\n--- Class Topper ---\n");
    printf("Roll: %d\n", s[topper].roll);
    printf("Name: %s\n", s[topper].name);
    printf("Percentage: %.2f\n", s[topper].percentage);
    printf("\n--- Students Failed in One or More Subjects ---\n");

    for (i = 0; i < n; i++) {
        for (j = 0; j < 5; j++) {
            if (s[i].marks[j] < 40) {
                printf("%d - %s\n", s[i].roll, s[i].name);
                break;
            }
        }
    }
    average = sum / n;
    printf("\nClass Average = %.2f\n", average);
    return 0;
}
