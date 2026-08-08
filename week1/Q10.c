#include <stdio.h>
int main() {
    float balance = 1000, amount;
    int choice, i, count = 0;
    char transactions[5][30];
    do {
        printf("\n\n--- ATM MENU ---");
        printf("\n1. Check Balance");
        printf("\n2. Deposit");
        printf("\n3. Withdraw");
        printf("\n4. Show Last 5 Transactions");
        printf("\n5. Exit");
        printf("\nEnter choice: ");
        scanf("%d", &choice);

        if (choice == 1)
        { printf("Balance = %.2f", balance); }
        
        else if (choice == 2) {
            printf("Enter amount: ");
            scanf("%f", &amount);
            balance = balance + amount;
            if (count < 5)
                count++;
            for (i = count - 1; i > 0; i--)
                sprintf(transactions[i], "%s", transactions[i - 1]);
            sprintf(transactions[0], "Deposited %.2f", amount);
            printf("Money deposited.");
        }

        else if (choice == 3) {
            printf("Enter amount: ");
            scanf("%f", &amount);
            if (amount <= balance) {
                balance = balance - amount;
                if (count < 5)
                    count++;
                for (i = count - 1; i > 0; i--)
                    sprintf(transactions[i], "%s", transactions[i - 1]);
                sprintf(transactions[0], "Withdrawn %.2f", amount);
                printf("Money withdrawn.");
            }
            else {
                printf("Insufficient balance.");
            }
        }

        else if (choice == 4) {
            printf("\nLast Transactions:\n");
            for (i = 0; i < count; i++)
                printf("%s\n", transactions[i]);
        }

        else if (choice == 5)
        { printf("Thank you!"); }

        else
        { printf("Invalid choice."); }
    } while (choice != 5);
    return 0;
}
