# Contact Book - C

A simple contact management system written in C.

## Features

* Add new contacts
* List all contacts
* Search contacts by name
* Delete contacts
* Dynamic memory allocation using `calloc()` and `realloc()`
* Input validation
* Menu-driven interface

## Concepts Used

This project was created to practice core C programming concepts:

* Structures (`struct`)
* Pointers
* Pointer to Pointer (`**`)
* Dynamic Memory Management

    * `calloc()`
    * `realloc()`
    * `free()`
* Strings

    * `fgets()`
    * `strcmp()`
    * `strcspn()`
* Arrays
* Functions
* Loops and Conditions

## How It Works

The program starts with an initial capacity for 5 contacts.

When the contact list becomes full, the program automatically increases its capacity using `realloc()`, allowing the user to continue adding contacts without restarting the program.

Contacts are stored using the following structure:

```c
struct Contacts {
    char name[20];
    char phone[20];
    char email[20];
};
```

## Menu

```text
==== Main Menu ====

1 - Contact List
2 - Add a New Contact
3 - Contact Search
4 - Delete a Contact

0 - Exit
```

## Example Usage

```text
==== Main Menu ====

1 - Contact List
2 - Add a New Contact
3 - Contact Search
4 - Delete a Contact

0 - Exit

Select option: 2

Please enter a contact name: John Doe
Please enter a phone number: 123456789
Please enter an email: john@example.com
```

## What I Learned

While building this project, I practiced:

* Managing memory manually
* Passing pointers to functions
* Using pointer-to-pointer parameters with `realloc()`
* Working with structures and arrays of structures
* Handling string input safely
* Implementing basic CRUD operations (Create, Read, Search, Delete)

## Future Improvements

* Edit existing contacts
* Save contacts to a file
* Load contacts from a file
* Sort contacts alphabetically
* Case-insensitive searching
* Better input validation

## Author

Furgan Gurbanli

GitHub: https://github.com/fGurbanli
