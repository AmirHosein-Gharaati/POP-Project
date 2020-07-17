#include "defines.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "select.h"

char command[200];

int scan_for_file_names(char* fileName){
    for (int i = 0; i < 100; i++)
    {
        fileName[i] = '\0';
    }
    
    int index=0;
    char c;
    
    while(1){
        c = getchar();
        if(c == '\n'){
            return 1;
        }
        if(c == '-'){
            char is_all[10];
            scanf("%s",is_all);
            if (strcmp(is_all,"all") == 0){
                return 2;
            }
        }
        if(c == '"'){
            break;
        }
    }

    while((c=getchar())!='"'){
        fileName[index] = c;
        index++;
    }    

    return 0;

}

int check_for_existed_file(char* file_name,FILE* file){

    int result;
    sprintf(command,"ls %s > /dev/null 2>&1",file_name);
    result = system(command);

    if (result == 512){
        return 2;
    }

    char buffer[100];
    int index;
    int len;
    fseek(file,0,SEEK_SET);
    while(fgets(buffer,100,file)){
        
        len = strlen(buffer);
        if (buffer[len-1] == '\n'){
            buffer[len-1] = '\0';
        }
        
        if(strcmp(buffer,file_name)== 0){
            return 0;
            
        }
    }
    return 1;
    
}

void select_all(){
    system("ls > ./.vcs/selecteds.txt");
    printf("All files selected\n");
    while(getchar()!='\n');
    return;

}

void select_files(){

    CLEAR_SCREEN

    char file_name[100];
    FILE* file;
    file = fopen("./.vcs/selecteds.txt","a+");

    while(1){

        int is_end_of_files;
        
        is_end_of_files = scan_for_file_names(file_name);
        if(is_end_of_files == 1){
            break;
        }
        else if(is_end_of_files == 2){
            select_all();
            break;
        }

        int result;
        result = check_for_existed_file(file_name,file);
    
        if (result == 0){
            printf("The file \"%s\" was previously selected\n",file_name);
            continue;
        }
        else if(result == 2){
            printf("The file %s does not exist\n",file_name);
            continue;
        }
        else{
            fprintf(file,"%s\n",file_name);
            printf("The file \"%s\" selected\n",file_name);
        }
    }
    
    fclose(file);
    printf("Press enter to continue\n");
    while(getchar()!='\n');
    
}