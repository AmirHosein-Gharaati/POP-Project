#include "defines.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "select.h"

/**
 * This function is using for selecting the file to commit
 */
void select_file(){

    char command[200];
    char file_name[100];

    while (getchar()!='"');

    char c;
    int index=0;

    while ((c=getchar())!='"')
    {
        file_name[index] = c;
        index++;
    }

    int result;
    sprintf(command,"ls %s > /dev/null 2>&1",file_name);
    result = system(command);

    if (result == 512){
        printf("The file %s does not exist",file_name);
        while(getchar()!='\n');
        getchar();
        return;
    }
    
    //we can just select 1 file simultaneously
    sprintf(command,"printf \"%s\" > ./.vcs/selecteds.txt",file_name);
    system(command);

    printf("the file \"%s\" selected\nPress enter to continue\n",file_name);
    PRESS_ENTER_TO_CONTINUE
}