#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Customer {
    char name[50];
    int age;
    char mobileno[20];
    float height;
    float weight;
    int slotTime;
};

void displaySlots() {
printf("1. 9:00 AM - 10:00 AM\n");
printf("2. 10:00 AM - 11:00 AM\n");
printf("3. 11:00 AM - 12:00 PM\n");
printf("4. 12:00 PM - 1:00 PM\n");
printf("5. 1:00 PM - 2:00 PM\n");
printf("6. 2:00 PM - 3:00 PM\n");
printf("7. 3:00 PM - 4:00 PM\n");
printf("8. 4:00 PM - 5:00 PM\n");
}

void addCustomer() {
    struct Customer c;
    FILE *fp;

    // Open file for appending
    fp = fopen("customers.txt", "a");

    // Check if file opened successfully
    if (fp == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    // Get customer details from user
    printf("Enter customer name: \n");
    scanf("%s",&c.name);
    printf("Enter customer age: \n");
    scanf("%d", &c.age);
    printf("Enter customer's contact no: \n");
    scanf("%s",&c.mobileno);
    printf("Enter customer height (in meters):  \n");
    scanf("%f", &c.height);
    printf("Enter customer weight (in kilograms):  \n");
    scanf("%f", &c.weight);

    // Display available slots
    printf("Available slots: \n");
    displaySlots();

    // Get slot time from user
    printf("Enter slot time: ");
    scanf("%d", &c.slotTime);

    // Write customer details to file
    fprintf(fp, "Name: %s , Age: %d , Mobile No: %s , Height: %.2f , Weight: %.2f , SlotTime No.: %d", c.name, c.age, c.mobileno, c.height, c.weight, c.slotTime);

    // Close file
    fclose(fp);

    printf("Customer record added successfully.\n");
}

void deleteCustomer() {
    char name[50];
    FILE *fp, *tempfp;
    char line[100];
    int found = 0;

    // Open original file for reading
    fp = fopen("customers.txt", "r");

    // Open temporary file for writing
    tempfp = fopen("temp.txt", "w");

    // Check if file opened successfully
    if (fp == NULL || tempfp == NULL) {
        printf("Error opening file.");
        exit(1);
    }

    // Get customer name to delete
    printf("Enter customer name to delete: ");
    scanf("%s", name);

    // Read file line by line and copy all lines except the one that matches the customer name to a temporary file
    while (fgets(line, 100, fp) != NULL) {
        if (strstr(line, name) == NULL) {
            fputs(line, tempfp);
        } else {
            found = 1;
        }
    }

    // Close files
    fclose(fp);
    fclose(tempfp);

    // Delete original file
    remove("customers.txt");

    // Rename temporary file to original file name
    rename("temp.txt", "customers.txt");

    if (found) {
        printf("Customer record deleted successfully.\n");
    } else {
        printf("Customer record not found.\n");
    }
}

void searchCustomer() {
    char name[50];
    FILE *fp;
    char line[100];
    int found = 0;
    char mobileno[20];

    // Open file for reading
    fp = fopen("customers.txt", "r");

    // Check if file opened successfully
    if (fp == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    // Get customer name to search for
    printf("Enter customer name to search for: \n");
    scanf("%s",&name);
    printf("\nEnter customer's contact no: \n");
    scanf("%s",&mobileno[20]);
    // Search for customer name in file
while (fgets(line, 100, fp) != NULL) {
    if ((strstr(line, name) != NULL) && (strstr(line,mobileno))) {
        // Display customer details
        printf("Customer details: %s\n", line);
        found = 1;
        break;
    }
}
// Close file
fclose(fp);

if (!found) {
    printf("Customer record not found.\n");
}
}

int main() {
int choice;
    printf("   \xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\n");
    printf("   \xcd\xcd\xcd\xcd\xcd\xcd FITNESS CLUB MANAGEMENT SYSTEM \xcd\xcd\xcd\xcd\xcd\xcd\n");
    printf("   \xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\n");
do {
    printf("\n");
    printf("1. Add Customer\n");
    printf("2. Delete Customer\n");
    printf("3. Search Customer\n");
    printf("4. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            addCustomer();
            break;
        case 2:
            deleteCustomer();
            break;
        case 3:
            searchCustomer();
            break;
        case 4:
            printf("Thank You <3 \n");
            break;
        default:
            printf("Invalid choice. Please try again.\n");
    }
} while (choice != 4);
return 0;
}
