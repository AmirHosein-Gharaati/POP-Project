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

//colors
#define RED   "\x1B[31m"
#define GREEN   "\x1B[32m"
#define YELLO   "\x1B[33m"
#define BLUE   "\x1B[34m"
#define PURPLE   "\x1B[35m"
#define LIGHT_BLUE   "\x1B[36m"
#define WHITE   "\x1B[37m"
#define RESET "\x1B[0m"