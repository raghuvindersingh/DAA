#include<stdio.h>
struct Book {
    int id;
    char title[30];
    char author[30];
    int total;
    int available;
};

int main() {
    struct Book b[50];
    int n = 0, choice, id, i;
    do {
        printf("\n1. Add Book");
        printf("\n2. Search Book");
        printf("\n3. Issue Book");
        printf("\n4. Return Book");
        printf("\n5. Unavailable Books");
        printf("\n6. Exit");
        printf("\nEnter choice: ");
        scanf("%d", &choice);

        if (choice == 1) {
            printf("Enter ID: ");
            scanf("%d", &b[n].id);
            printf("Enter title: ");
            scanf("%s", b[n].title);
            printf("Enter author: ");
            scanf("%s", b[n].author);
            printf("Enter total copies: ");
            scanf("%d", &b[n].total);
            b[n].available = b[n].total;
            n++;
            printf("Book added.");
        }

        else if (choice == 2) {
            printf("Enter ID: ");
            scanf("%d", &id);
            for (i = 0; i < n; i++) {
                if (b[i].id == id) {
                    printf("Title: %s\n", b[i].title);
                    printf("Author: %s\n", b[i].author);
                    printf("Available: %d\n", b[i].available);
                }
            }
        }

        else if (choice == 3) {
            printf("Enter ID: ");
            scanf("%d", &id);
            for (i = 0; i < n; i++) {
                if (b[i].id == id && b[i].available > 0) {
                    b[i].available--;
                    printf("Book issued.");
                }
            }
        }

        else if (choice == 4) {
            printf("Enter ID: ");
            scanf("%d", &id);
            for (i = 0; i < n; i++) {
                if (b[i].id == id && b[i].available < b[i].total) {
                    b[i].available++;
                    printf("Book returned.");
                }
            }
        }

        else if (choice == 5) {
            printf("\nUnavailable Books:\n");
            for (i = 0; i < n; i++) {
                if (b[i].available == 0)
                    printf("%d - %s\n", b[i].id, b[i].title);
            }
        }
    } while (choice != 6);
    return 0;
}
