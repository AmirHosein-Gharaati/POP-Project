#include "defines.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "select.h"

char command[200];

/**
 * This function is using for scannig names of files
 * @param fileName The variable which we want to store the name of file in it
 * @return 0 if found name, 1 if reached to the end of line, 2 if used switch -all, 3 if used -show
 */
int scan_for_file_names(char* file_name){
    
    //clearing fileName
    for (int i = 0; i < 100; i++){
        file_name[i] = '\0';
    }
    
    int index=0;
    char c;
    
    while(1){
        c = getchar();
        if(c == '\n'){
            return 1;
        }
        if(c == '-'){
            char sswitch[10];
            scanf("%s",sswitch);

            if (strcmp(sswitch,"all") == 0){
                return 2;
            }

            else if(strcmp(sswitch,"show") ==0){
                return 3;
            }
        }
        if(c == '"'){
            break;
        }
    }

    while((c=getchar())!='"'){
        file_name[index] = c;
        index++;
    }    

    return 0;

}
/**
 * This function is using for if the file we selected exist and if it has been selected befor
 * @param file_name The name of the file
 * @param file The file which we want to read all the selected files
 * @return 0 if the was selected before, 1 if executed successfully, 2 if there was not any file existed with this name
 */
int check_for_existed_file(char* file_name,FILE* file){

    int result;
    sprintf(command,"ls %s > /dev/null 2>&1",file_name);
    result = system(command);

    if (result != 0){
        return 2;
    }

    char selected_name[100];
    int index;
    int len;
    fseek(file,0,SEEK_SET);
    while(fgets(selected_name,100,file)){
        
        len = strlen(selected_name);
        if (selected_name[len-1] == '\n'){
            selected_name[len-1] = '\0';
        }
        
        if(strcmp(selected_name,file_name)== 0){
            return 0;
            
        }
    }
    return 1;
    
}

/**
 * This function store all the file names into the selecteds.txt file
 */
void select_all(){
    system("ls > ./.vcs/selecteds.txt");
    printf("All files selected\n");
    while(getchar()!='\n');
    return;

}

/**
 * This function selects the name of files
 */
void select_files(){
    CLEAR_SCREEN

    char file_name[100];
    int result;
    FILE* file;
    file = fopen("./.vcs/selecteds.txt","a+");

    //selecting files names until we reach to \n
    while(1){

        int result_of_scanning_files;
        
        result_of_scanning_files = scan_for_file_names(file_name);
        if(result_of_scanning_files == 1){
            break;
        }
        else if(result_of_scanning_files == 2){
            select_all();
            break;
        }

        else if(result_of_scanning_files == 3){
            printf(YELLO"Selected files:\n\n"RESET);
            system("cat ./.vcs/selecteds.txt");
            system("echo");
            system("echo =============");
            system("echo ");
            while(getchar()!='\n');
            break;
        }

        result = check_for_existed_file(file_name,file);
    
        //selected befor
        if (result == 0){
            printf(RED"The file \"%s\" was previously selected\n"RESET,file_name);
            continue;
        }

        //no file with this name
        else if(result == 2){
            printf(RED"The file %s does not exist\n"RESET,file_name);
            continue;
        }

        //printing the name of file into to selecteds.txt file
        else{
            fprintf(file,"%s\n",file_name);
            printf(GREEN"The file \"%s\" selected\n"RESET,file_name);
        }
    }
    fclose(file);

    printf("Press enter to continue\n");
    while(getchar()!='\n');
}