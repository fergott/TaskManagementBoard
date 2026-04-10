// Task3 and Task4 will go in here
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "define.h"

void edit_list(List *list) // Function to edit a list
{
    getchar(); // flushing newline to avoid fgets skipping input
    char editName[MAX];

    printf("Enter name of the list to edit:");
    fgets(editName, MAX, stdin);
    delete_newline(editName); // Remove the newline character from the input string
    if (editName[strlen(editName) - 1] != ':')
        strcat(editName, ":"); // Ensure the list name ends with a colon for matching

    List *found = find_list(list, editName);
    if (found == NULL)
    {
        printf("No list named \"%s\" found.\n", editName);
        return; // Intention here is that if user don't know what list they exist, they can go back to main menu and display the board first.
                // If we just go and try to ask the input again, they might get stuck in the loop.
    }
    int option = 0;
    while (option != 4) // Loop until user chooses to exit
    {

        char nameToBeEdited[MAX];

        printEditOptions();
        if (scanf("%i", &option) != 1)
        {
            while (getchar() != '\n')
                ;       // flush input
            option = 0; // reset to keep looping
            continue;
        }
        getchar(); // flush newline after scanf to avoid potential fgets skipping
        switch (option)
        {
        case 1:
        {
            // edit a name of the item
            printf("Enter the name of the item to edit: ");
            fgets(nameToBeEdited, MAX, stdin);
            delete_newline(nameToBeEdited);
            Item *item_found = find_item(found, nameToBeEdited);

            if (item_found == NULL)
            {
                printf("No such item \n");
                break;
            }
            else
            {
                printf("Enter new name for the item %s:", item_found->name);
                char newName[MAX];
                fgets(newName, MAX, stdin);
                delete_newline(newName);
                strcpy(item_found->name, newName);
            }
            break;
        }
        case 2:
        {
            // add a new item
            char newItem[MAX];
            printf("Enter the name of list to add: ");
            fgets(newItem, MAX, stdin);
            delete_newline(newItem);
            Item *new_item = malloc(sizeof(Item));
            if (new_item == NULL)
            {
                printf("memory allocation failed\n");
                break;
            }
            strcpy(new_item->name, newItem);
            new_item->next = found->item; // point new item to current first
            found->item = new_item;       // make new item the first
            printf("Item %s added\n", new_item->name);
            break;
        }
        case 3:
        {
            // delete at item
            char deleteName[MAX];
            printf("Enter the name to delete: ");
            fgets(deleteName, MAX, stdin);
            delete_newline(deleteName);

            Item *current = found->item;
            Item *prev = NULL;

            while (current != NULL)
            {
                if (strcmp(current->name, deleteName) == 0)
                {
                    if (prev == NULL)
                        found->item = current->next;
                    else
                        prev->next = current->next;
                    printf("Item %s deleted\n", current->name);
                    free(current);
                    break;
                }
                prev = current;
                current = current->next;
            }

            if (current == NULL)
            {
                printf("No such item \n");
                break;
            }

            break;
        }
        case 4:
        {
            // exit back to main menu
            break;
        }
        default:
        {
            printf("Enter a valid choice");
            break;
        }
        }
    }
}

void edit_board(List *list) // Function to edit the board
{
    getchar(); // flushing newline to avoid fgets skipping input
    int option = 0;
    while (option != 4)
    {
        printEditOptionsList();
        if (scanf("%i", &option) != 1)
        {
            while (getchar() != '\n')
                ;
            option = 0; // reset to keep looping
            continue;
        }
        getchar();

        switch (option)
        {
        case 1:
        {
            // edit a name of the list
            char listToBeEdited[MAX];
            printf("Enter the name of the list to edit: ");
            fgets(listToBeEdited, MAX, stdin);
            delete_newline(listToBeEdited);
            if (listToBeEdited[strlen(listToBeEdited) - 1] != ':')
                strcat(listToBeEdited, ":");
            List *list_found = find_list(list, listToBeEdited);
            if (list_found == NULL)
            {
                printf("No list named \"%s\" found.\n", listToBeEdited);

                break;
            }

            else
            {
                printf("Enter new name for the list %s ", list_found->name);
                char newName[MAX];
                fgets(newName, MAX, stdin);
                delete_newline(newName);
                if (newName[strlen(newName) - 1] != ':')
                    strcat(newName, ":");
                strcpy(list_found->name, newName);
            }
            break;
        }
        case 2:
        {
            // add a new list

            char newList[MAX];
            printf("Enter the name of list to add: ");
            fgets(newList, MAX, stdin);
            delete_newline(newList);
            if (newList[strlen(newList) - 1] != ':')
                strcat(newList, ":");
            List *new_list = malloc(sizeof(List));
            if (new_list == NULL)
            {
                printf("memory allocation failed\n");
                break;
            }

            strcpy(new_list->name, newList);
            new_list->item = NULL;
            new_list->prev = list;
            if (list->next != NULL)
                list->next->prev = new_list;
            new_list->next = list->next;
            list->next = new_list;
            printf("List %s added\n", new_list->name);
            break;
        }
        case 3:
        {
            // delete a list
            char deleteName[MAX];
            printf("Enter the name of the list to delete: ");
            fgets(deleteName, MAX, stdin);
            delete_newline(deleteName);
            if (deleteName[strlen(deleteName) - 1] != ':')
                strcat(deleteName, ":");

            List *target = find_list(list, deleteName);
            if (target == NULL)
            {
                printf("No list named \"%s\" found.\n", deleteName);
                break;
            }

            if (target->prev != NULL)
                target->prev->next = target->next;
            else
                board = target->next;
            if (target->next != NULL)
                target->next->prev = target->prev;

            Item *item = target->item;
            while (item != NULL)
            {
                Item *tmp = item->next;
                free(item);
                item = tmp;
            }
            free(target);
            printf("List \"%s\" deleted.\n", deleteName);
            break;
        }

        case 4:
        {
            // exit
            break;
        }
        default:
        {
            printf("Enter a valid choice \n");
            break;
        }
        }
    }
}
