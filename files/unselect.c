#include "defines.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "unselect.h"
#include "select.h"

#define SWITHC_ALL 2
#define END_OF_LINE 1

char command[300];

/**
 * This function is using for unselecting all files
 */
void unselect_all(){
    system("sed -i '1,$d' ./.vcs/selecteds.txt");
    printf("All files unselected\n");
    PRESS_ENTER_TO_CONTINUE
    return;
}

/**
 * This function is using for deleting a specefic line
 * @param unselect_file_name The name of the file which we want to unselect
 * @return 0 if found the name, 1 if didn't find the name
 */
int remove_line(char unselect_file_name[]){

    int line =1;
    FILE* file;
    file = fopen("./.vcs/selecteds.txt","r");

    char name[100];

    while(fgets(name,100,file)){
        REMOVE_BACK_SLASH_N(name);

        if(strcmp(unselect_file_name,name) == 0){

            //removing the line using sed command
            sprintf(command,"sed -i \'%dd\' ./.vcs/selecteds.txt",line);
            system(command);
            fclose(file);
            return 0;
        }
        line++;
    }

    fclose(file);
    return 1;

}


/**
 * This function is using for unselecting files.
 */
void unselect_file(){
    char file_name[100];
    int remove_line_result;
    
    //scannig file names until we reach to \n character
    while(1){
        int result = scan_for_file_names(file_name);

        if (result== SWITHC_ALL){
            unselect_all();
            return;
        }
        else if (result == END_OF_LINE){
            break;
        }
        
        remove_line_result = remove_line(file_name);
    }

    if(remove_line_result == 0){
        printf(GREEN"The file has been unselected.\n"RESET"Press enter to continue\n");
    }
    else{
        printf(RED"It was not selected before.\n"RESET"Press enter to continue\n");
    }
    
    while(getchar()!='\n');
}