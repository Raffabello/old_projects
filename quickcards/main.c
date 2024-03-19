#include <stdio.h>
#include <time.h>
#include <string.h>
#include <stdlib.h>

#define file_name_size 50
#define no_flashcard 100
#define WRONG "\e[0;31m"
#define CORRECT "\e[0;32m"
#define GUESS_WORD "\e[0;33m"
#define INFO "\e[1;37m"
#define reset "\e[0m"

#define LIFE_POINTS_DEFAULT 10


int main(void)
{

    FILE *test_file;
    char name_of_file[file_name_size];
    char word[10];
    //你开一件文件的时候如果这件文件不存在软件来NULL
    //问用户什么文件他要打开
    //如果文件名不存在软件就创造一新的文件,但是调查用户接受

    //这个编码的部分还没玩
    test_file = fopen("testfile", "r");
    //
    if(test_file == NULL)
    {
        int decision;
        printf("软件没找到你输入的文件,你想要创造这件文件吗\n输入1：要\n输入0:不要");
        scanf("%d", &decision);
        if(decision == 0)
            return 0;
        else
            {
                printf("请问输入文件的名字(%d个字母以下):\n",file_name_size);
                scanf("%s", name_of_file);
                FILE* new_file = fopen(name_of_file, "r");
                if(new_file == NULL)
                    exit(EXIT_FAILURE);
                else
                {
                    printf("文件创造了");
                    fclose(new_file);
                    return 1;
                }
            }
    }

    char flashcards[no_flashcard][file_name_size];
    int line_counter = 0;
    while(fscanf(test_file,"%s", flashcards[line_counter]) == 1 && line_counter < no_flashcard)
        line_counter ++;
    //游戏开始
    char stop_game_command[] = {"stop"};
    char user_command[file_name_size];
    int tmp_index;
    int tmp_index2;
    printf(INFO "---\n一般的信息\n");
    printf("名字\t\t生活点数\n");
    printf("User\t\t%d\n", LIFE_POINTS_DEFAULT);
    printf("词语数:%d\n---\n",line_counter);
    printf("游戏开始了!!\n如果你要关这个软件就输入'/stop'\n" reset);
    do
    {
        random_number:
        tmp_index = (rand() % line_counter);
        if(tmp_index % 2 != 0 || tmp_index == tmp_index2)
            goto random_number;
        printf("猜这个词语(" GUESS_WORD "%s" reset ")的意思？", flashcards[tmp_index]);
        scanf("%s", user_command);
        
        if(strcmp(user_command,flashcards[tmp_index + 1]) == 0)
        {
            printf(CORRECT "对！你的回答是正确的\n" reset);
        }
        if(strcmp(user_command,flashcards[tmp_index + 1]) != 0 && strcmp(user_command, "/stop") != 0)
        {
            printf( WRONG "错误！正确回答是【%s】\n" reset , flashcards[tmp_index + 1]);
        }
        tmp_index2 = tmp_index;
    }while(strcmp(user_command, "/stop") != 0);

    printf("软件停止了为用我的软件非常谢！\n开发者：Raffabello");
    return 1;
}
