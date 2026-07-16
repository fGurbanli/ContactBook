#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Contacts {
    char name[20];
    int phone;
    char email[20];

};

void PrintMenu();
void AddContact();
void ListContact();
void DeleteContact();
int SearchContact();

int GetIntInput();

int main(void)
{
    int count = 5;
    int* contSize = malloc(count * sizeof(int));

    PrintMenu();

    int option = GetIntInput();
    switch (option) {
        case 1:
            printf("Openning contact list...\n");
            ListContact();
        case 2:
            AddContact();
        case 3:
            SearchContact();
        case 4:
            DeleteContact();
        case 0:
            printf("Shutting down the program");
            exit(0);
    }

    free(contSize);
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