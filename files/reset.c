#include "defines.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "reset.h"

/**
 * This varibale is used for executing a command in system().
 */
char command[500];


/**
 * This function is using for reset a commit id.
 * @param reset_commit_id An integer which is the commit id that we want to reset.
 * @return 1 if did not execute and 0 if executed successfully
 */
int reset(int reset_commit_id){

    //checking if the commit id exist or not
    sprintf(command,"ls ./.vcs/commits/%d > /dev/null 2>&1",reset_commit_id);
    int result;
    result = system(command);
    if (result !=0){
        printf(RED"The commit id does not exist.\nPress enter to continue\n"RESET);
        PRESS_ENTER_TO_CONTINUE
        return 1;
    }
    

    //removing all files except "main" (parallel required)
    system("ls | grep -v main | parallel rm -rf");


    char file_name[100];
    FILE* file;
    sprintf(file_name,"./.vcs/commits/%d/.assigned.txt",reset_commit_id);
    file = fopen(file_name,"r");

    //reseting all selected files
    while(fgets(file_name,100,file)){
        REMOVE_BACK_SLASH_N(file_name);

        int commit_id =1;
        sprintf(command,"cp \"./.vcs/firstVersionOfFiles/%s\" ./",file_name);
        system(command);

        //patching from the first patch to reset_commit_id
        while(commit_id <= reset_commit_id){
            sprintf(command,"ls ./.vcs/commits/%d/%s.patch > /dev/null 2>&1",commit_id,file_name);
            result = system(command);
            if (result == 0){
                sprintf(command,"bspatch %s %s ./.vcs/commits/%d/%s.patch",file_name,file_name,commit_id,file_name);
                system(command);
            }
            commit_id++;
            
        }
    }
    fclose(file);
    
    printf(GREEN"Successfully executed.\nPress enter to continue\n"RESET);
    PRESS_ENTER_TO_CONTINUE
    return 0;
}