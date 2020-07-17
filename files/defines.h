#define SWITCH(parameter)\
    char save[100];\
    int flag=0;\
    strcpy(save,parameter);\
    {\

#define CASE(string)\
    if (strcmp(string,save) == 0){flag=1;}\
    if(strcmp(string,save) == 0 || flag == 1)\
    
#define BREAK\
    flag=0;\
    continue;

#define EndSwitch }


#define CLEAR_SCREEN\
    system("clear");\
    fflush(stdin);


#define REMOVE_BACK_SLASH_N(variable) if (variable[strlen(variable)-1] == '\n'){variable[strlen(variable)-1] = '\0';}



#define PRESS_ENTER_TO_CONTINUE\
    while(getchar()!='\n');\
    while(getchar()!='\n');


#define ACCESS_COMMAND if(system("ls ./.vcs > /dev/null 2>&1") != 0){printf("You have to initialize first\n");while(getchar()!='\n');while(getchar()!='\n');flag=0;continue;}