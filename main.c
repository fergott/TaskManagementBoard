#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "define.h"

List *board;

int main()
{
    board = defined_board();
    while (1)
    {
        int nC;
        printWelcome();
        scanf("%d", &nC);

        switch (nC)
        {
        case 1:
            display_board(board);
            break;
        case 2:
            //load board from a file
            break;
        case 3:
            // Edit list functionality
                editList(board);
            break;
        case 4:
            // Edit Board functionality
                editBoard(board);
            break;
        case 5:
            // Save board to a file functionality
            break;
        case 6:
            // Quit functionality
            exit(0);


        default:
            printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}