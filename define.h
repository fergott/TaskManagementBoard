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
void display_board(List *board);          // Function to display the board
int printWelcome();                       // Function to print the welcome message and get user input
void load_from_file();                    // Function to load board from a file
List *find_list(List *board, char *name); // Function to find a list by name for Task 3 and Task 4

#endif // DEFINE_H