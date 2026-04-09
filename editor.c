// Task3 and Task4 will go in here
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "define.h"

void editList(List *list)
{
    char editName[MAX];

    printf("Enter name to edit:");
    scanf("%s", editName);
    //  delete_newline(editName);

    List *found = find_list(list, editName);
    if (found == NULL)
    {
        printf("\ncant find list try again cunt\n");
        printf("%s \n", editName);
        printf("%s \n", list->name);
    }
    else
    {
        char nameToBeEdited[MAX];
        int option;
        printEditOptions();
        scanf("%i", &option);
        getchar();
        switch (option)
        {
        case 1:
        {
            // edit a name of the item
            printf("Enter the name of the item to edit \n");
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
            printf("Enter the name of list to add");
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
            printf("Enter the name to delete:");
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
            // exit (I believe just break should be sufficient
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

void editBoard(List *list)
{
    int option = 0;
    char editName[MAX];

    printEditOptionsList();
    scanf("%i", &option);
    getchar();

    List *found = find_list(list, editName);
    if (found == NULL)
    {
        printf("\ncant find list try again cunt\n");
        printf("%s \n", editName);
        printf("%s \n", list->name);
    }
    switch (option)
    {
    case 1:
    {
        // edit a name of the item

        char listToBeEdited[MAX];
        printf("Enter the name of the list to edit:");

        fgets(listToBeEdited, MAX, stdin);
        delete_newline(listToBeEdited);
        List *list_found = find_list(found, listToBeEdited);

        if (list_found == NULL)
        {
            printf("No such list \n");
            break;
        }
        else
        {
            printf("Enter new name for the list %s:", list_found->name);
            char newName[MAX];
            fgets(newName, MAX, stdin);
            delete_newline(newName);
            strcpy(list_found->name, newName);
        }
        break;
    }
    case 2:
    {
        // add a new item
        char newList[MAX];
        printf("Enter the name of list to add");
        fgets(newList, MAX, stdin);
        delete_newline(newList);
        List *new_list = malloc(sizeof(List));
        if (new_list == NULL)
        {
            printf("memory allocation failed\n");
            break;
        }

        strcpy(new_list->name, newList);
        new_list->next = found->next;
        found->next = new_list;
        printf("List %s added\n", new_list->name);
        break;
    }
    case 3:
    {
        // delete at item
        char deleteName[MAX];
        printf("Enter the name to delete:");
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
                printf("list %s deleted\n", current->name);
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

void delete_newline(char *str)
{
    int len = strlen(str);
    if (len > 0 && str[len - 1] == '\n')
    {
        str[len - 1] = '\0';
    }
}

Item *find_item(List *list, char *name)
{
    Item *current = list->item;
    while (current != NULL)
    {
        if (strcmp(current->name, name) == 0)
            return current;
        current = current->next;
    }
    return NULL;
}
