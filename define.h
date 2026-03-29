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
    Item *first_item;
    struct List *next;
    struct List *prev;
} List;

extern List *board;

// func prototype
List *defined_board();
void display_board(List *board);
void printWelcome();
void load_from_file();

#endif // DEFINE_H