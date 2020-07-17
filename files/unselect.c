#include "defines.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "unselect.h"
#include "select.h"


void unselect_all(){
    system("sed -i '1,$d' ./.vcs/selecteds.txt");
    printf("All files unselected\n");
    PRESS_ENTER_TO_CONTINUE
    return;
}


/**
 * This function is using for unselecting files.
 */
void unselect_file(){
    char file_name[100];
    char command[300];

    while(1){
        int result = scan_for_file_names(file_name);
        if (result== 2){
            unselect_all();
            return;
        }
        else if (result == 1){
            break;
        }
        sprintf(command,"sed -i \'/%s/d\' ./.vcs/selecteds.txt",file_name);
        system(command);

    }
    
    printf("The file has been unselected.\nPress enter to continue\n");
    while(getchar()!='\n');
}