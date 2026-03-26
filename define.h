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

#endif // DEFINE_H