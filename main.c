#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "define.h"

List *board;

int main()
{
    printAsciiArt();
    board = defined_board();
    while (1)
    {
        int nC;
        nC = print_welcome();

        switch (nC)
        {
        case 1:
            display_board(board);
            break;
        case 2:
        {
            List *tmp = load_board_from_file();
            if (tmp != NULL) // only update the board if the file loading was successful
                board = tmp;
            break;
        }
        case 3:
            // Edit list functionality
                edit_list(board);
            break;
        case 4:
            // Edit Board functionality
                edit_list(board);
            break;
        case 5:
            write_board_to_file(board);
            break;
        case 6:
            exit(0);
            break;

        default:
            printf("Invalid choice. Please try again.\n");
            printf("\n");
            break;
        }
    }

    return 0;
}