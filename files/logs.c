#include "defines.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "init.h"


/**
 * This function is using for printing the logs text.
 */
void logs(){
    CLEAR_SCREEN

    FILE* file;
    file = fopen("./.vcs/logs.txt","r");
    char c;

    while((c=getc(file))!=EOF){
        putchar(c);
    }
    
    printf("\nPress enter to continue\n");
    getchar();
    getchar();
}