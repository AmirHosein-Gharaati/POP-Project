#include "defines.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "unselect.h"
#include "select.h"

char command[300];

void unselect_all(){
    system("sed -i '1,$d' ./.vcs/selecteds.txt");
    printf("All files unselected\n");
    PRESS_ENTER_TO_CONTINUE
    return;
}

void remove_line(char unselect_file_name[]){
    int line =1;
    FILE* file;
    file = fopen("./.vcs/selecteds.txt","r");

    char name[100];

    while(fgets(name,100,file)){
        REMOVE_BACK_SLASH_N(name);

        if(strcmp(unselect_file_name,name) == 0){

            sprintf(command,"sed -i \'%dd\' ./.vcs/selecteds.txt",line);
            system(command);
            break;
        }
        line++;
    }

}


/**
 * This function is using for unselecting files.
 */
void unselect_file(){
    char file_name[100];
    

    while(1){
        int result = scan_for_file_names(file_name);
        if (result== 2){
            unselect_all();
            return;
        }
        else if (result == 1){
            break;
        }
        
        remove_line(file_name);
    }
    
    printf("The file has been unselected.\nPress enter to continue\n");
    while(getchar()!='\n');
}