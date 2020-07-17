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
        printf("The folder \".vcs\" already exists\nDo you want to reinitialize?(y/n)");
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

    system("mkdir ./.vcs/commits");
    system("mkdir ./.vcs/stash");
    system("mkdir ./.vcs/lastVersionOfFiles");
    system("touch ./.vcs/logs.txt");
    system("touch ./.vcs/status.txt");
    system("touch ./.vcs/selecteds.txt");
    system("touch ./.vcs/allFiles.txt");
    
    printf("Initialized successfully.\nPress enter to continue\n");

    PRESS_ENTER_TO_CONTINUE
    CLEAR_SCREEN
    return;
}