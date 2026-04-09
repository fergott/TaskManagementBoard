#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "define.h"

List *load_board_from_file() // Function to load a board from a file
{
    char filename[MAX]; // buffer for filename
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
    char line[MAX];

    while (fgets(line, MAX, file))
    {
        line[strcspn(line, "\n")] = 0; // Remove newline character
        char *trimmed = line;          // for trimming the space at custom file input **this assumes that test input file follow the format of test.txt
        while (*trimmed == ' ' || *trimmed == '\t')
            trimmed++;

        if (trimmed[strlen(trimmed) - 1] == ':') // If the line ends with a ":", it's a list name, otherwise it's an item name
        {
            List *new_list = malloc(sizeof(List));
            strcpy(new_list->name, trimmed);
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
            if (current_list == NULL)
                continue; // If there is no current list, that is an error in file format, skip the item
            Item *new_item = malloc(sizeof(Item));
            strcpy(new_item->name, trimmed);
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

void write_board_to_file(List *board)
{
    char filename[MAX];
    printf("Enter filename: ");
    scanf("%s", filename);

    FILE *file = fopen(filename, "w");
    if (file == NULL)
    {
        printf("Error: could not open file %s\n", filename);
        return;
    }

    List *current_list = board;

    while (current_list != NULL) // loop until the end of the list, write the list name and its items to the file
    {
        fprintf(file, "%s\n", current_list->name);
        Item *current_item = current_list->item;
        while (current_item != NULL)
        {
            fprintf(file, "    %s\n", current_item->name);
            current_item = current_item->next;
        }
        current_list = current_list->next;
    }
    fclose(file);
}
