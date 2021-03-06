#include "defines.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "init.h"
#include "select.h"
#include "unselect.h"
#include "commit.h"
#include "reset.h"
#include "logs.h"
#include "stash.h"
#include "status.h"

#define BLUE  "\x1B[34m"
#define WHITE  "\x1B[37m"

//gcc main.c select.c init.c unselect.c commit.c logs.c reset.c stash.c status.c -o main

/**
 * This function prints the menu of program
 */
void menu(){

    printf(LIGHT_BLUE"\t\t\t********************\n");
    printf("\t\t\t*AG version control*\n");
    printf("\t\t\t********************\n"RESET);
    printf(RED"Commands:\n\n"RESET);

    printf("init\nstatus\nselect [file name]\nunselect [file name]\ncommit [commit description]\nlogs\nreset [commit id]\nstash [commit id]\nhelp\nexit\n");
    printf("\n> ");
}


int main(){

    while (1)
    {
        CLEAR_SCREEN
        menu();
        char command[100];
        scanf("%s",command);
        
        SWITCH(command)

            CASE("init"){
                CLEAR_SCREEN
                init();
                BREAK;
            }

            CASE("select"){
                CLEAR_SCREEN
                ACCESS_COMMAND
                select_files();
                BREAK;
            }

            CASE("unselect"){
                CLEAR_SCREEN
                ACCESS_COMMAND
                unselect_file();
                BREAK;
            }

            CASE("logs"){
                CLEAR_SCREEN
                ACCESS_COMMAND
                logs();
                BREAK;
            }

            CASE("commit"){
                CLEAR_SCREEN
                ACCESS_COMMAND
                commit();
                BREAK;
            }

            CASE("reset"){
                CLEAR_SCREEN
                int commit_id;
                scanf("%d",&commit_id);
                ACCESS_COMMAND
                reset(commit_id);
                BREAK;
            }

            CASE("stash"){
                CLEAR_SCREEN
                ACCESS_COMMAND
                stash();
                BREAK;
            }

            CASE("status"){
                CLEAR_SCREEN
                ACCESS_COMMAND
                status();
                BREAK;
            }

            CASE("help"){
                CLEAR_SCREEN
                system("xdg-open https://github.com/AmirHosein-Gharaati/POP-Project > /dev/null 2>&1");
                BREAK;
            }

            CASE("exit"){
                return 0;
            }

            //default
            printf("Wrong command!\nPress enter to continue\n");
            PRESS_ENTER_TO_CONTINUE

        EndSwitch

    }
    
    return 0;
}