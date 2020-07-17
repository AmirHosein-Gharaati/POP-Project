#include "defines.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "commit.h"


char command[300];

/**
 * This function is using for commiting for the first time
 * @param file_name Name of the file for commiting
 * @param commit_id Commit id
 */
void commit_first_time(char* file_name,int commit_id){
    
    //saving the first version of file
    sprintf(command,"cp \"%s\" ./.vcs/commits/%d > /dev/null 2>&1",file_name,commit_id);
    system(command);
    
    //saving the last version of file
    sprintf(command,"cp \"%s\" ./.vcs/lastVersionOfFiles/ > /dev/null 2>&1",file_name);
    system(command);

    //adding the file to the list of all files
    sprintf(command,"printf \"%s\n\" >> ./.vcs/allFiles.txt",file_name);
    system(command);

    //assigning the commit to the corresponding file
    sprintf(command,"printf \"%s\n\" >> ./.vcs/commits/%d/.assigned.txt",file_name,commit_id);
    system(command);
}



/**
 * This function is using for commiting the file if the file commited before
 * @param file_name Name of the file for commiting
 * @param commit_id Commit id
 */
void commit_after_first_time(char* file_name,int commit_id){

    //saving the difference of the file and last version of file to a patch file
    sprintf(command,"bsdiff ./.vcs/lastVersionOfFiles/%s %s ./.vcs/commits/%d/%s.patch",file_name,file_name,commit_id,file_name);
    system(command);

    //assigning the commit to the corresponding file
    sprintf(command,"printf \"%s\n\" >> ./.vcs/commits/%d/.assigned.txt",file_name,commit_id);
    system(command);

    //removing the last version of file
    sprintf(command,"rm ./.vcs/lastVersionOfFiles/%s",file_name);
    system(command);

    //copying the file which is the last version of file after commit
    sprintf(command,"cp %s ./.vcs/lastVersionOfFiles/ > /dev/null 2>&1",file_name);
    system(command);


}



/**
 * This function is using for scanning the description of commit
 * @param description Variable to save description in it
 */
void scan_description(char* description){
    char c;
    int index=0;
    while(getchar()!='"');
    while((c=getchar())!='"'){
        description[index] = c;
        index++;
    }
    while(getchar()!='\n');
}




/**
 * This function is using for commiting the file
 */
void commit(){

    char description[100];
    scan_description(description);


    //making a folder for commit
    int commit_id=1;
    while (1)
    {
        int result;
        sprintf(command,"ls ./.vcs/commits/%d > /dev/null 2>&1",commit_id);
        result = system(command);

        if (result!=0){
            sprintf(command,"mkdir ./.vcs/commits/%d",commit_id);
            system(command);

            sprintf(command,"touch ./.vcs/commits/%d/.assigned.txt",commit_id);
            system(command);

            break;
        }

        else{
            commit_id++;
        }
    }


    //saving the commit informations
    sprintf(command,"printf \"Commit ID : %d\n\tCommit Description: %s\n\tDate : \" >> ./.vcs/logs.txt",
    commit_id,
    description);
    system(command);
    sprintf(command,"date >> ./.vcs/logs.txt");
    system(command);


    char selected_file_name[100];
    FILE* file;
    file = fopen("./.vcs/selecteds.txt","r");
    

    FILE* allFiles;
    allFiles = fopen("./.vcs/allFiles.txt","r+");
    char allFiles_name[100];
    int flag;

    while(fgets(selected_file_name,100,file)){
        REMOVE_BACK_SLASH_N(selected_file_name);
    
        flag =0;
        fseek(allFiles,0,SEEK_SET);
        while(fgets(allFiles_name,100,allFiles)){
            REMOVE_BACK_SLASH_N(allFiles_name);

            if (strcmp(allFiles_name,selected_file_name) == 0){
                flag =1;
                break;
            }

        }
        
        if (flag == 1){
            commit_after_first_time(selected_file_name,commit_id);
        }

        else{
            commit_first_time(selected_file_name,commit_id);
        }

    }

    fclose(allFiles);
    fclose(file);

    printf("Commited successfully\nPress enter to continue\n");
    getchar();
}