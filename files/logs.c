#include "defines.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "init.h"


/**
 * This function is using for printing the logs text.
 */
void logs(){
    CLEAR_SCREEN
    printf(LIGHT_BLUE"Logs :\n"RESET);
    system("cat ./.vcs/logs.txt");
    
    printf("\nPress enter to continue\n");
    PRESS_ENTER_TO_CONTINUE
}