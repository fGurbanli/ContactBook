#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Contacts {
    char name[20];
    int phone;
    char email[20];

};

void printMenu();
void AddContact();
void ListContact();
void DeleteContact();
int SearchContact();

int main(void) {
    int count = 5;
    int* contSize = malloc(count * sizeof(int));
    struct Contacts contacts[*contSize];





    free(contSize);
    return 0;
}