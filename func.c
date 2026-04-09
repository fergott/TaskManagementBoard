#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "define.h"

List *defined_board()
{
    List *list1 = malloc(sizeof(List));
    strcpy(list1->name, "Abey");

    list1->next = NULL;

    Item *item1_1 = malloc(sizeof(Item));
    strcpy(item1_1->name, "Oculus Pro");

    Item *item1_2 = malloc(sizeof(Item));
    strcpy(item1_2->name, "Oculus Quest 1");

    item1_2->next = NULL;
    list1->first_item = item1_1;
    item1_1->next = item1_2;

    List *list2 = malloc(sizeof(List));
    strcpy(list2->name, "Dante");

    list2->next = list1;

    Item *item2_1 = malloc(sizeof(Item));
    strcpy(item2_1->name, "Oculus Quest 1");

    item2_1->next = NULL;

    Item *item2_2 = malloc(sizeof(Item));
    strcpy(item2_2->name, "3070 RTX");

    item2_2->next = NULL;

    list2->first_item = item2_1;
    item2_1->next = item2_2;

    List *list3 = malloc(sizeof(List));
    strcpy(list3->name, "Tim");

    list3->next = list2;

    Item *item3_1 = malloc(sizeof(Item));
    strcpy(item3_1->name, "Oculus Quest 2");

    list3->first_item = item3_1;
    item3_1->next = NULL;

    List *list4 = malloc(sizeof(List));
    strcpy(list4->name, "Nick");

    Item *item4_1 = malloc(sizeof(Item));
    strcpy(item4_1->name, "3070 RTX");

    item4_1->next = NULL;

    list4->first_item = item4_1;
    list4->next = list3;
    list1->prev = list2;
    list2->prev = list3;
    list3->prev = list4;
    list4->prev = NULL;

    return list4;
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
Item *find_item(List *list, char *name)
{
    Item *current = list->first_item;
    while (current != NULL)
    {
        if (strcmp(current->name, name) == 0)
            return current;
        current = current->next;
    }
    return NULL;
}

void display_board(List *board)
{
    List *current_list = board;
    while (current_list != NULL)
    {
        printf("%s\n", current_list->name);
        Item *current_item = current_list->first_item;
        while (current_item != NULL)
        {
            printf("    %s\n", current_item->name);
            current_item = current_item->next;
        }
        current_list = current_list->next;
    }
    printf("\n");
}

void printWelcome()
{
    printf("Menu:\n");
    printf("1. Display board\n");
    printf("2. Load board from a file\n");
    printf("3. Edit list\n");
    printf("4. Edit Board\n");
    printf("5. Save board to a file\n");
    printf("6. Quit\n");
    printf("Enter your choice(1-6):");
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

void writeData(List *board)
{
    char filename[MAX];
    printf("Enter file name:");
    scanf("%s", filename);

    List *current_list = board;
    FILE *fptr = fopen(filename, "wb");
    while (current_list != NULL)
    {
        fwrite(current_list->name, strlen(current_list->name), 1, stdout);
    }
    fclose(fptr);
}

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

                //edit a name of the item
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
                    fgets(newName, MAX,stdin);
                    delete_newline(newName);
                    strcpy(item_found->name, newName);
                }
                break;
            case 2:
                {
                //add a new item
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
                    new_item->next = found->first_item;  // point new item to current first
                    found->first_item = new_item;         // make new item the first
                    printf("Item %s added\n", new_item->name);
                break;
            }
            case 3:
                //delete at item
                char deleteName[MAX];
                printf("Enter the name to delete:");
                fgets(deleteName, MAX, stdin);
                delete_newline(deleteName);

                Item *current = found->first_item;
                Item *prev = NULL;

                while (current != NULL) {
                   if ( strcmp(current->name, deleteName) == 0)
                   {
                       if (prev == NULL)
                           found->first_item = current->next;
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
            case 4:
                //exit (I believe just break should be sufficient
                break;
            default:
                printf("Enter a valid choice");
                break;
            }
        }

}
void editBoard(List *list) {
    int option =0;
    char editName[MAX];

    scanf("%i", &option);
    printEditOptionsList();

    List *found = find_list(list, editName);
    if (found == NULL)
    {
        printf("\ncant find list try again cunt\n");
        printf("%s \n", editName);
        printf("%s \n", list->name);
    }
    switch (option) {
        case 1:
            //edit a name of the item

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
                fgets(newName, MAX,stdin);
                delete_newline(newName);
                strcpy(list_found->name, newName);
            }
            break;
        case 2:
        {
            //add a new item
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
        case 3:
            //delete at item
            char deleteName[MAX];
            printf("Enter the name to delete:");
            fgets(deleteName, MAX, stdin);
            delete_newline(deleteName);

            Item *current = found->first_item;
            Item *prev = NULL;

            while (current != NULL) {
                if ( strcmp(current->name, deleteName) == 0)
                {
                    if (prev == NULL)
                        found->first_item = current->next;
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

        case 4:
            //exit
            break;
        default:
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
