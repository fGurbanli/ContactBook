#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Contacts {
    char name[20];
    char phone[20];
    char email[20];

};

void PrintMenu();
void AddContact(struct Contacts* contacts, int* currentCount,int* maxSize);
void ListContact(struct Contacts* contacts, int* currentCount);
void DeleteContact(struct Contacts* contacts, int* currentCount);
void SearchContact(struct Contacts* contacts, int* currentCount);

int GetIntInput();

int main(void)
{
    int maxSize = 5;
    int currentCount = 0;

    struct Contacts* contacts = calloc(maxSize, sizeof(struct Contacts));
    if (contacts == NULL) {
        printf("\nMemory allocation failed!");
        free(contacts);
        return 1;
    }

    while (1)
    {
        PrintMenu();

        int option = GetIntInput();
        switch (option) {
            case 1:
                printf("Openning contact list...\n");
                ListContact(contacts, &currentCount);
                break;
            case 2:
                AddContact(contacts, &currentCount, &maxSize);
                break;
            case 3:
                SearchContact(contacts, &currentCount);
                break;
            case 4:
                DeleteContact(contacts, &currentCount);
                break;
            case 0:
                printf("Shutting down the program");
                free(contacts);
                exit(0);
            default:
                printf("Invalid option!");
        }
    }
    free(contacts);
    return 0;
}

void PrintMenu()
{
    printf("====Main Menu====\n");
    printf("1-Contact list\n");
    printf("2-Add a new contact\n");
    printf("3-Contact search\n");
    printf("4-Delete a contact\n");
    printf("\n0-Exit\n");
}

void AddContact(struct Contacts* contacts, int* currentCount, int* maxSize){
    if (*currentCount == *maxSize)
    {
        *maxSize *= 2;
        struct Contacts* temp = realloc(contacts, (*maxSize) * sizeof(struct Contacts));
        if (temp == NULL) {
            printf("\nMemory allocation failed!");
            free(contacts);
            return;
        }
        contacts = temp;

        printf("Please enter a contact name: ");
        fgets(contacts[*currentCount].name, sizeof(contacts[*currentCount].name), stdin);
        contacts[*currentCount].name[strcspn(contacts[*currentCount].name, "\n")] = '\0';

        printf("Please enter a phone number: ");
        fgets(contacts[*currentCount].phone, sizeof(contacts[*currentCount].phone), stdin);
        contacts[*currentCount].phone[strcspn(contacts[*currentCount].phone, "\n")] = '\0';

        printf("Please enter an email");
        fgets(contacts[*currentCount].email, sizeof(contacts[*currentCount].email), stdin);
        contacts[*currentCount].email[strcspn(contacts[*currentCount].email, "\n")] = '\0';
    }

    printf("Please enter a contact name: ");
    fgets(contacts[*currentCount].name, sizeof(contacts[*currentCount].name), stdin);

    printf("Please enter a phone number: ");
    fgets(contacts[*currentCount].phone, sizeof(contacts[*currentCount].phone), stdin);

    printf("Please enter an email");
    fgets(contacts[*currentCount].email, sizeof(contacts[*currentCount].email), stdin);

    (*currentCount)++;
}

void ListContact(struct Contacts* contacts, int* currentCount)
{
    int input;
    while (currentCount <= 0) {
        printf("\n There is no contact yet!");
        printf("\n Enter 0 to go back: ");
        input = GetIntInput();
        if (input == 0) {
            return;
        }
    }
    for (int i = 0; i < *currentCount; i++)
    {
        printf("%s\n", contacts[i].name);
        printf("%s\n", contacts[i].phone);
        printf("%s\n\n", contacts[i].email);
    }
}

void SearchContact(struct Contacts* contacts, int* currentCount)
{
    char searchName[20];
    printf("\nPlease enter a name for search: ");
    fgets(searchName, sizeof(searchName), stdin);
    searchName[strcspn(searchName, "\n")] = '\0';

    for (int i = 0; i < *currentCount; i++)
    {
        if (!(strcmp(searchName, contacts[i].name)))
        {

            printf("Contact found!\n");
            printf("%s\n", contacts[i].name);
            printf("%s\n", contacts[i].phone);
            printf("%s\n\n", contacts[i].email);
            return;
        }
    }
}

void DeleteContact(struct Contacts* contacts, int* currentCount)
{
    char searchName[20];
    printf("\nPlease enter a name for delete: ");
    fgets(searchName, sizeof(searchName), stdin);
    searchName[strcspn(searchName, "\n")] = '\0';

    for (int i = 0; i < *currentCount; i++)
    {
        if (!(strcmp(searchName, contacts[i].name)))
        {
            for (int j = i; j < *currentCount; j++)
            {
                contacts[j] = contacts [j+1];
                (*currentCount)--;
                printf("Contact '%s' deleted successfully!\n", searchName);
            }
        }
        printf("Contact not found: %s\n", searchName);
    }
}


int GetIntInput()
{
    int input;
    while (1)
    {
        if (scanf("%d", &input) == 1 && input >= 0)
        {
            break;
        }
        printf("Enter a valid value!");
        while (getchar() != '\n');
    }
    return input;
}