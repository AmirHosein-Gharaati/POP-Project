#include "defines.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stash.h"
#include "reset.h"

/**
 * This function is using for stash command.
 */
void stash(){
    char command[300];
    
    char id_or_pop[10];
    scanf("%s",id_or_pop);

    if(strcmp(id_or_pop,"pop") == 0){
        //checking if stash folder is empty or not
        system("[ \"$(ls -A ./.vcs/stash)\" ] && echo \"N\" || echo Empty > t.txt");
        if (system("ls t.txt > /dev/null 2>&1") == 0){
            system("rm t.txt");
            printf("You can not pop!\nPress enter to continue\n");
            getchar();
            getchar();
            return;
        }
        

        system("ls | grep -v main | parallel rm -rf");
        system("mv ./.vcs/stash/* ./");
    }

    else{

        system("cp * -r ./.vcs/stash/");

        int commit_id = atoi(id_or_pop);
        reset(commit_id);
    }
}