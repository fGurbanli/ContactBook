#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Contacts {
    char* name;
    char* phone;
    char* email;
};

void PrintMenu();
void AddContact(struct Contacts** contacts, int* currentCount,int* maxSize);
void ListContact(struct Contacts* contacts, int* currentCount);
void DeleteContact(struct Contacts* contacts, int* currentCount);
void SearchContact(struct Contacts* contacts, int* currentCount);

int GetIntInput();

int main(void)
{
    FILE* contactFile = fopen("contacts.txt", "w");

    if (contactFile == NULL)
    {
        printf("File could not be opened!\n");
        return 1;
    }


    int maxSize = 5;
    int currentCount = 0;

    struct Contacts* contacts = calloc(maxSize, sizeof(struct Contacts));
    if (contacts == NULL) {
        printf("\nMemory allocation failed!");
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
                AddContact(&contacts, &currentCount, &maxSize);
                break;
            case 3:
                SearchContact(contacts, &currentCount);
                break;
            case 4:
                DeleteContact(contacts, &currentCount);
                break;
            case 0:
                printf("Shutting down the program");
                for (int i = 0; i < currentCount; i++)
                {
                    free(contacts[i].name);
                    free(contacts[i].phone);
                    free(contacts[i].email);

                }
                free(contacts);
                exit(0);
            default:
                printf("Invalid option!");
        }
    }
}

void PrintMenu()
{
    printf("\n");
    printf("====Main Menu====\n");
    printf("1-Contact list\n");
    printf("2-Add a new contact\n");
    printf("3-Contact search\n");
    printf("4-Delete a contact\n");
    printf("\n0-Exit\n");
}

void AddContact(struct Contacts** contacts, int* currentCount, int* maxSize) {
    while (getchar()!= '\n');
    if (*currentCount == *maxSize)
    {
        *maxSize *= 2;
        struct Contacts* temp = realloc(*contacts, (*maxSize) * sizeof(struct Contacts));
        if (temp == NULL) {
            printf("\nMemory allocation failed!");
            return;
        }
        for (int i = *currentCount; i < *maxSize; i++)
        {
            (*contacts)[i].name = NULL;
            (*contacts)[i].phone = NULL;
            (*contacts)[i].email = NULL;
        }
        *contacts = temp;
    }
    char temp[100];

    printf("\nPlease enter a contact name: ");
    fgets(temp, sizeof(temp), stdin);
    temp[strcspn(temp, "\n")] = '\0';
    (*contacts)[*currentCount].name = malloc(strlen(temp) + 1);

    if ((*contacts)[*currentCount].name == NULL) {
        printf("\nMemory allocation failed!");
        return;
    }
    strcpy((*contacts)[*currentCount].name, temp);

    printf("Please enter a phone number: ");
    fgets(temp, sizeof(temp), stdin);
    temp[strcspn(temp, "\n")] = '\0';
    (*contacts)[*currentCount].phone = malloc(strlen(temp) + 1);

    if ((*contacts)[*currentCount].phone == NULL) {
        printf("\nMemory allocation failed!");
        return;
    }
    strcpy((*contacts)[*currentCount].phone, temp);


    printf("Please enter an email: ");
    fgets(temp, sizeof(temp), stdin);
    temp[strcspn(temp, "\n")] = '\0';
    (*contacts)[*currentCount].email = malloc(strlen(temp) + 1);

    if ((*contacts)[*currentCount].email == NULL) {
        printf("\nMemory allocation failed!");
        return;
    }
    strcpy((*contacts)[*currentCount].email, temp);

    (*currentCount)++;
}

void ListContact(struct Contacts* contacts, int* currentCount)
{
    printf("\n");
    int input;
    while (*currentCount <= 0) {
        printf("\nThere is no contact yet!");
        printf("\nEnter 0 to go back: ");
        input = GetIntInput();
        if (input == 0) {
            printf("\n\n");
            return;
        }
    }
    for (int i = 0; i < *currentCount; i++)
    {
        printf("--Contact %d--\n", i+1);
        printf("%s\n", contacts[i].name);
        printf("%s\n", contacts[i].phone);
        printf("%s\n\n", contacts[i].email);
    }
}

void SearchContact(struct Contacts* contacts, int* currentCount)
{
    while (getchar()!= '\n');
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
    printf("Contact does not exist!\n");
}

void DeleteContact(struct Contacts* contacts, int* currentCount)
{
    while (getchar()!= '\n');
    ListContact(contacts, currentCount);
    printf("\nPlease enter an index of contact: ");
    int index = GetIntInput() - 1;

    if (index >= *currentCount || index < 0) {
        printf("\nEnter a valid index!");
        return;
    }
    free(contacts[index].name);
    free(contacts[index].phone);
    free(contacts[index].email);
    (*currentCount)--;
    for (int i = index; i < *currentCount - 1; i++) {

        contacts[i] = contacts[i + 1];
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