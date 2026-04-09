#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "define.h"

List *defined_board() // Function to create a predefined board
{
    List *list1 = malloc(sizeof(List));
    strcpy(list1->name, "Abey:");

    list1->next = NULL;

    Item *item1_1 = malloc(sizeof(Item));
    strcpy(item1_1->name, "Oculus Pro");

    Item *item1_2 = malloc(sizeof(Item));
    strcpy(item1_2->name, "Oculus Quest 1");

    item1_2->next = NULL;
    list1->item = item1_1;
    item1_1->next = item1_2;

    List *list2 = malloc(sizeof(List));
    strcpy(list2->name, "Dante:");

    list2->next = list1;

    Item *item2_1 = malloc(sizeof(Item));
    strcpy(item2_1->name, "Oculus Quest 1");

    item2_1->next = NULL;

    Item *item2_2 = malloc(sizeof(Item));
    strcpy(item2_2->name, "3070 RTX");

    item2_1->next = item2_2;

    item2_2->next = NULL;

    list2->item = item2_1;
    item2_1->next = item2_2;

    List *list3 = malloc(sizeof(List));
    strcpy(list3->name, "Tim:");

    list3->next = list2;

    Item *item3_1 = malloc(sizeof(Item));
    strcpy(item3_1->name, "Oculus Quest 2");

    list3->item = item3_1;
    item3_1->next = NULL;

    List *list4 = malloc(sizeof(List));
    strcpy(list4->name, "Nick:");

    Item *item4_1 = malloc(sizeof(Item));
    strcpy(item4_1->name, "3070 RTX");

    item4_1->next = NULL;

    list4->item = item4_1;
    list4->next = list3;
    list1->prev = list2;
    list2->prev = list3;
    list3->prev = list4;
    list4->prev = NULL;

    return list4; // Return the head of the list
}

List *find_list(List *board, char *name) // helper function to find a list by name for Task 3 and Task 4
{
    List *current = board;
    while (current != NULL)
    {
        if (strcmp(current->name, name) == 0)
        {
            return current;
        }
        current = current->next;
    }
    return NULL;
}

void display_board(List *board) // Function to display the board
{
    List *current_list = board;
    while (current_list != NULL)
    {
        printf("%s\n", current_list->name);
        Item *current_item = current_list->item;
        while (current_item != NULL)
        {
            printf("    %s\n", current_item->name);
            current_item = current_item->next;
        }
        current_list = current_list->next;
    }
    printf("\n");
}

int print_welcome()
{
    int nC;
    printf("Menu:\n");
    printf("1. Display board\n");
    printf("2. Load board from a file\n");
    printf("3. Edit list\n");
    printf("4. Edit Board\n");
    printf("5. Save board to a file\n");
    printf("6. Quit\n");
    printf("Enter your choice(1-6):");
    if (scanf("%d", &nC) != 1)
    {
        while (getchar() != '\n')
            ;      // flush input
        return -1; // triggers the default case (this is to avoid the infinite loop when input is not an integer)
    }
    printf("\n");
    return nC;
}

void printEditOptions()
{
    printf("Options:\n");
    printf("1. Edit an item\n");
    printf("2. Add a new item\n");
    printf("3. Delete an item\n");
    printf("4. Return to main menu\n");
    printf("Enter your choice(1-4):");
}
void printEditOptionsList()
{
    printf("Options:\n");
    printf("1. Edit an list\n");
    printf("2. Add a new list\n");
    printf("3. Delete a list\n");
    printf("4. Return to main menu\n");
    printf("Enter your choice(1-4):");
}

void printAsciiArt() // ascii art printing
{
    printf("##    ##  ########  ##     ##  #######  ########\n");
    printf("##    ##  ##        ##     ## ##     ## ##    ##\n");
    printf("##    ##  ##        ##     ## ##     ## ##    ##\n");
    printf(" ######   ######    ######### ##     ## ########\n");
    printf("  ##      ##        ##     ## ##     ## ##  ##  \n");
    printf("  ##      ##        ##     ## ##     ## ##   ## \n");
    printf("  ##      ########  ##     ##  #######  ##    ##\n");
    printf("\n");
    printf("##         ##  ######  #####   ##   ## \n");
    printf(" ##       ##    ##   ##       ##  ##   \n");
    printf("  ##    ##     ##   ##       ####      \n");
    printf("    ####      ##   ##       ##  ##     \n");
    printf("     ##    ######   #####  ##    ##    \n");
    printf("\n");
}