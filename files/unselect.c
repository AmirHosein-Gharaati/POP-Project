#include "defines.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "unselect.h"


/**
 * This function is using for unselecting files.
 */
void unselect_file(){
    system("sed -i \'1,$d\' ./.vcs/selecteds.txt");
    
    printf("The file has been unselected.\nPress enter to continue\n");
    PRESS_ENTER_TO_CONTINUE
}