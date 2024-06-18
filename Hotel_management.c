#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CUSTOMERS 100

// Structure to store customer information
struct Customer {
    char fullName[100];
    char phoneNumber[20];
    char checkInDate[20];
};

// Array to store customer records
struct Customer customers[MAX_CUSTOMERS];
int numCustomers = 0;

// Function prototypes
void checkIn();
void displayCustomers();

int main() {
    int choice;

    while (1) {
        printf("\n***** Hotel Management System *****\n");
        printf("1. Check In\n");
        printf("2. Display Customer List\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                checkIn();
                break;
            case 2:
                displayCustomers();
                break;
            case 3:
                printf("Exiting program...\n");
                exit(0);
            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }
    }

    return 0;
}

void checkIn() {
    struct Customer newCustomer;

    printf("\nEnter Full Name: ");
    getchar(); // Clear the newline character left by previous scanf
    fgets(newCustomer.fullName, sizeof(newCustomer.fullName), stdin);
    newCustomer.fullName[strcspn(newCustomer.fullName, "\n")] = '\0'; // Remove newline

    printf("Enter Phone Number: ");
    fgets(newCustomer.phoneNumber, sizeof(newCustomer.phoneNumber), stdin);
    newCustomer.phoneNumber[strcspn(newCustomer.phoneNumber, "\n")] = '\0'; // Remove newline

    printf("Enter Check-in Date (YYYY-MM-DD): ");
    fgets(newCustomer.checkInDate, sizeof(newCustomer.checkInDate), stdin);
    newCustomer.checkInDate[strcspn(newCustomer.checkInDate, "\n")] = '\0'; // Remove newline

    // Add customer to the list
    customers[numCustomers++] = newCustomer;

    printf("\n%s has been checked in.\n", newCustomer.fullName);
}

void displayCustomers() {
    printf("\n***** Customer List *****\n");
   

    for (int i = 0; i < numCustomers; ++i) {
        printf("Full Name: %s\nPhone Number: %s\nCheck-in Date: %s\n",customers[i].fullName, customers[i].phoneNumber, customers[i].checkInDate);
    }
}
