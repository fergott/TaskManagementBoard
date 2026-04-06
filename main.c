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
        nC = printWelcome();

        switch (nC)
        {
        case 1:
            display_board(board);
            break;
        case 2:
            board = load_board_from_file();
            break;
        case 3:
            // Edit list functionality
            break;
        case 4:
            // Edit Board functionality
            break;
        case 5:
            // Save board to a file functionality
            break;
        case 6:
            exit(0);
            break;

        default:
            printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}