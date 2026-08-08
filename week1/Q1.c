#include <stdio.h>

int main() {
    int a[100], n;
    int largest, second;
    int i;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter elements: ");
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);

    largest = a[0];
    second = -99;

    for (i = 1; i < n; i++) {
        if (a[i] > largest) {
            second = largest;
            largest = a[i];
        }
        else if (a[i] > second && a[i] != largest) {
            second = a[i];
        }
    }

    if (second == -99)
        printf("No second largest distinct element.");
    else
        printf("Second largest element = %d", second);

    return 0;
}
