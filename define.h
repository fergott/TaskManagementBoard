#ifndef DEFINE_H
#define DEFINE_H

typedef struct Item
{
    char name[255];
    struct Item *next;
} Item;

typedef struct List
{
    char name[255];
    Item *item;
    struct List *next;
    struct List *prev;
} List;

extern List *board;

// func prototype
List *defined_board();                    // Function to create a predefined board
List *load_board_from_file();             // Function to load a board from a file
List *find_list(List *board, char *name); // Function helper to find a list by name for Task 3 and Task 4
List *edit_item_list(List *board);        // Function to edit an item from the list
List *edit_list(List *board);             // Function to edit a list from the board

void display_board(List *board);       // Function to display the board
void load_from_file();                 // Function to load board from a file
void write_board_to_file(List *board); // Function to write the board to a file

int print_welcome();  // Function to print the welcome message and get user input
void printAsciiArt(); // Function to print ASCII art

#endif // DEFINE_H