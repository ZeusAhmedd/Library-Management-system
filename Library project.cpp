#include <stdio.h>
#include <string.h>

const int MAX_BOOKS = 100; // Maximum number of books
const int TITLE_LENGTH = 100; // Maximum length of book title
const int NAME_LENGTH = 100; // Maximum length of borrower's name

struct Book {
    char title[TITLE_LENGTH];
    char location[20]; // e.g., "Row 1, Aisle 2"
    char borrowedBy[NAME_LENGTH]; // Name of the student who borrowed the book
    int isAvailable; // 1 if available, 0 if borrowed
};

void searchBook(struct Book library[], int bookCount, const char *searchTitle) {
    for (int i = 0; i < bookCount; i++) {
        if (strcmp(library[i].title, searchTitle) == 0) {
            if (library[i].isAvailable) {
                printf("The book '%s' is available at %s.\n", library[i].title, library[i].location);
            } else {
                printf("The book '%s' is currently borrowed by %s.\n", library[i].title, library[i].borrowedBy);
            }
            return;
        }
    }
    printf("The book '%s' is not found in the library.\n", searchTitle);
}

int main() {
    struct Book library[MAX_BOOKS] = {
        {"C Programming", "Row 1, Aisle 1", "", 1},
        {"Data Structures", "Row 1, Aisle 2", "", 0},
        {"Algorithms", "Row 2, Aisle 1", "Alice", 0},
        
        {"Operating Systems", "Row 2, Aisle 2", "", 1},
        {"Database Systems", "Row 3, Aisle 1", "Ali", 0}
    };
    
    int bookCount = 5;
    char searchTitle[TITLE_LENGTH];

    printf("Welcome to the Library Management System\n");
    printf("Enter the title of the book you want to search for: ");
    fgets(searchTitle, TITLE_LENGTH, stdin);
    searchTitle[strcspn(searchTitle, "\n")] = 0; // Remove newline character

    searchBook(library, bookCount, searchTitle);

    return 0;
}

