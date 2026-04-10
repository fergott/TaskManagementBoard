#ifndef DEFINE_H
#define DEFINE_H

#define MAX 255 // maximum length for list and item names

typedef struct Item
{
    char name[MAX];    // name of the item
    struct Item *next; // pointer to next item in the list
} Item;

typedef struct List
{
    char name[MAX];    // name of the list
    Item *item;        // pointer to the first item in the list
    struct List *next; // pointer to the next list
    struct List *prev; // pointer to the previous list
} List;

extern List *board;

// func prototype
List *defined_board();                    // Function to create a predefined board
List *load_board_from_file();             // Function to load a board from a file
List *find_list(List *board, char *name); // Function helper to find a list by name for Task 3 and Task 4
Item *find_item(List *list, char *name);  // Function helper to find an item by name for Task 3 and Task 4

void edit_board(List *board);          // Function to edit an item from the list
void edit_list(List *board);           // Function to edit a list from the board
void display_board(List *board);       // Function to display the board
void load_from_file();                 // Function to load board from a file
void write_board_to_file(List *board); // Function to write the board to a file
void printEditOptions();               // Function to print the edit options for items
void printEditOptionsList();           // Function to print the edit options for lists
void delete_newline(char *str);        // Function to delete the newline character from a string
void printAsciiArt();                  // Function to print ASCII art

int print_welcome(); // Function to print the menu message and get user input

#endif // DEFINE_H