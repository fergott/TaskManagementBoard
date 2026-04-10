#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "define.h"

// Global variable for board
List *board;

int main()
{
    // Print ASCII Art at the start of the program
    printAsciiArt();

    // Initialize the board
    board = defined_board();
    while (1)
    {
        int nC;               // choice for the main menu
        nC = print_welcome(); // call print_welcome function

        switch (nC)
        {
        case 1:
            // Display board
            display_board(board);
            break;
        case 2:
        {
            // Load board from a file
            List *tmp = load_board_from_file(); // load from the file and store it temporarily
            if (tmp != NULL)
                board = tmp; // only assign to board if loading
            break;
        }
        case 3:
            // Edit list functionality
            edit_list(board);
            break;
        case 4:
            // Edit Board functionality
            edit_board(board);
            break;
        case 5:
            // Save board to a file
            write_board_to_file(board);
            break;
        case 6:
            // Quit the program
            exit(0);
            break;

        default:
            // Invalid input handling
            printf("Invalid choice. Please try again.\n");
            printf("\n");
            break;
        }
    }

    return 0;
}