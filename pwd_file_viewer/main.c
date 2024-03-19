#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define FILE_NAME_MAX_SIZE 50

/*
软件入门：怎么表现文件名的词汇
开发者:自己
说明：
    这个软件比表现文件夹的所有文件名。
    源码不是难的，这个软件用Linux的命米”ls”这样
    把文件夹所有的文件名复印在新的文件，然后
    把这个新的文件取消了
*/

int main(void)
{
    FILE *tmp_file;
    char file_name[50];
    int file_found_counter = 0;
    char throwaway;
    system("ls > tmp_file_list");
    tmp_file = fopen("tmp_file_list","r");
    int index = 0;
    while(fscanf(tmp_file,"%s",file_name) == 1)
    {
        printf("[%d]%s\n",file_found_counter,file_name);
        file_found_counter++;    
    }
    char found_file[file_found_counter][FILE_NAME_MAX_SIZE];
    int current_index = 0;
    while(fscanf(tmp_file,"%s",file_name) == 1)
    {
        fscanf(tmp_file,"%s",found_file[current_index]);
        current_index++;
    }
    fclose(tmp_file);
    remove("tmp_file_list");
    return 0;
}
