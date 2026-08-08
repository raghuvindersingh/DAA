#include<stdio.h>
#include<string.h>

int main() {
    char str[100];
    int i=0, j, flag = 1;
    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);
    j = strlen(str) - 1;

    while (i < j) {
        if (str[i] == ' ') {
            i++;
            continue;
        }
        if (str[j] == ' ' || str[j] == '\n') {
            j--;
            continue;
        }

        if (str[i] >= 'A' && str[i] <= 'Z')
            str[i] = str[i] + 32;
        if (str[j] >= 'A' && str[j] <= 'Z')
            str[j] = str[j] + 32;
        if (str[i] != str[j]) {
            flag = 0;
            break;
        }
        i++, j--;
    }

    if (flag)
        printf("Palindrome");
    else
        printf("Not a palindrome");
    return 0;
}
