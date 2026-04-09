#ifndef DEFINE_H
#define DEFINE_H
#define MAX 100
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
void editList(List *list);
void delete_newline(char *str);
void editBoard(List *board);
#endif // DEFINE_H