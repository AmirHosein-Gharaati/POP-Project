#include "defines.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "status.h"

/**
 * This function is using for printing the status.
 */
void status(){

    char command[300];
    int flag;

    //creating a file which its context is the list of the current files in main folder.
    system("ls > ./.vcs/currentFiles.txt");

    FILE* current_files;
    current_files = fopen("./.vcs/currentFiles.txt","r");

    FILE* allFiles;
    allFiles = fopen("./.vcs/allFiles.txt","r");

    char name_of_current_files[100],
    name_of_allFiles[100];

    system("echo \"Modified files:\" > ./.vcs/Modified.txt");
    system("echo \"New files:\" > ./.vcs/NewFiles.txt");
    system("echo \"Deleted files:\" > ./.vcs/Deleted.txt");

    
    /*comparing current files to all files
        There are 2 cases:
            1 : equal names and different files == Modified
            2 : no matched name of current files == New file 
    */
    while(fgets(name_of_current_files,100,current_files)){
        REMOVE_BACK_SLASH_N(name_of_current_files);
        flag=0;

        fseek(allFiles,0,SEEK_SET);
        while(fgets(name_of_allFiles,100,allFiles)){
            REMOVE_BACK_SLASH_N(name_of_allFiles);

            if(strcmp(name_of_allFiles,name_of_current_files) == 0){
                flag = 1;

                int result;
                sprintf(command,"diff \"%s\" \"./.vcs/lastVersionOfFiles/%s\" > /dev/null 2>&1",
                name_of_current_files,
                name_of_current_files);
                
                result = system(command);
                if (result != 0){
                    sprintf(command,"printf \"\t%s\n\" >> ./.vcs/Modified.txt",name_of_current_files);
                    system(command);
                    //printf("Modified : %s\n",name_of_current_files);
                }

                break;
            }
        }

        if (flag ==0){
            sprintf(command,"printf \"\t%s\n\" >> ./.vcs/NewFiles.txt",name_of_current_files);
            system(command);
        }
    }



    /*comparing all files to current files
        There is 1 :
            1 : no matched name in all files in repo == Deleted
    */
    fseek(allFiles,0,SEEK_SET);
    while(fgets(name_of_allFiles,100,allFiles)){
        REMOVE_BACK_SLASH_N(name_of_allFiles);

        flag=0;
        fseek(current_files,0,SEEK_SET);
        while(fgets(name_of_current_files,100,current_files)){
            REMOVE_BACK_SLASH_N(name_of_current_files);

            if (strcmp(name_of_current_files,name_of_allFiles)==0){
                flag=1;
                break;
            }
            
        }

        if (flag == 0){
            sprintf(command,"printf \"\t%s\n\" >> ./.vcs/Deleted.txt",name_of_allFiles);
            system(command);
        }
        
    }

    fclose(allFiles);
    fclose(current_files);

    //printing the files context and then removing them
    
    system("cat ./.vcs/Modified.txt");
    system("echo =================");
    
    system("cat ./.vcs/Deleted.txt");
    system("echo =================");
    
    system("cat ./.vcs/NewFiles.txt");

    system("rm ./.vcs/Modified.txt ./.vcs/Deleted.txt ./.vcs/NewFiles.txt");
    

    PRESS_ENTER_TO_CONTINUE
    
}