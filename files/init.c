#include "defines.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "init.h"

    
/**
 * This function is using for initializing the folder
 */
void init(){
    
    int result = system("mkdir .vcs >/dev/null 2>&1");

    if (result != 0){
        printf(RED"The folder \".vcs\" already exists\n\n"RESET"Do you want to reinitialize?(y/n)");
        getchar();

        char yes_or_no[10];
        scanf("%s",yes_or_no);
        if (yes_or_no[0] == 'y'||yes_or_no[0] == 'Y'){
            system("rm -rf .vcs");
            system("mkdir .vcs >/dev/null 2>&1");
        }
        else
        {
            CLEAR_SCREEN
            return; 
        } 
    }

    //making folders and files for initialization
    system("mkdir ./.vcs/commits");
    system("mkdir ./.vcs/stash");
    system("mkdir ./.vcs/lastVersionOfFiles");
    system("mkdir ./.vcs/firstVersionOfFiles");
    system("touch ./.vcs/logs.txt");
    system("touch ./.vcs/status.txt");
    system("touch ./.vcs/selecteds.txt");
    system("touch ./.vcs/allFiles.txt");
    
    printf(GREEN"Initialized successfully.\n"RESET"Press enter to continue\n");

    PRESS_ENTER_TO_CONTINUE
    CLEAR_SCREEN
    return;
}