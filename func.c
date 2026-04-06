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

List *load_board_from_file() // Function to load a board from a file
{
    char filename[255]; // buffer for filename
    printf("Enter filename: ");
    scanf("%s", filename);

    FILE *file = fopen(filename, "r");
    if (file == NULL)
    {
        printf("Error: could not open file %s\n", filename);
        return NULL;
    }

    List *head = NULL;         // head of the list
    List *current_list = NULL; // pointer to the current list in processing
    char line[255];

    while (fgets(line, 255, file))
    {
        line[strcspn(line, "\n")] = 0; // Remove newline character

        if (line[strlen(line) - 1] == ':') // If the line ends with a ":", it's a list name, otherwise it's an item name
        {
            List *new_list = malloc(sizeof(List));
            strcpy(new_list->name, line);
            new_list->item = NULL;
            new_list->next = NULL;
            new_list->prev = NULL;

            if (current_list != NULL) // If there is a current list, link the new list to it
            {
                current_list->next = new_list;
                new_list->prev = current_list;
            }
            else // If there is no current list, this is the head of the list
            {
                head = new_list;
            }
            current_list = new_list; // Move the current list pointer to the new list
        }
        else
        {
            Item *new_item = malloc(sizeof(Item));
            strcpy(new_item->name, line);
            new_item->next = NULL;

            if (current_list->item == NULL) // If the current list has no items, set the new item as the first item
            {
                current_list->item = new_item;
            }
            else // If the current list already has items, find the last non NULL item and link the new item to it
            {
                Item *current_item = current_list->item;
                while (current_item->next != NULL) // loop until the last non NULL item is found
                {
                    current_item = current_item->next;
                }
                current_item->next = new_item;
            }
        }
    }

    return head;
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

int printWelcome()
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
    scanf("%d", &nC);
    return nC;
}