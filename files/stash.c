#include "defines.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stash.h"
#include "reset.h"

/**
 * This function is using for stash command
 */
void stash(){
    char command[300];
    
    char id_or_pop[10];
    scanf("%s",id_or_pop);

    if(strcmp(id_or_pop,"pop") == 0){

        //checking if stash folder is empty or not
        system("[ \"$(ls -A ./.vcs/stash)\" ] || echo Empty > t.txt");

        if (system("ls t.txt > /dev/null 2>&1") == 0){
            system("rm t.txt");

            printf(RED"You can not pop!\nPress enter to continue\n"RESET);
            PRESS_ENTER_TO_CONTINUE
            return;
        }
        
        system("ls | grep -v main | parallel rm -rf");
        system("mv ./.vcs/stash/* ./");
        printf(GREEN"Pop successfully!\nPress enter to continue\n"RESET);
        PRESS_ENTER_TO_CONTINUE
    }

    else{

        //copying all files into the stash folder
        system("rm -rf ./.vcs/stash/*");
        system("cp * -r ./.vcs/stash/");
        int commit_id = atoi(id_or_pop);
        reset(commit_id);
    }
}