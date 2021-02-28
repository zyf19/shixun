#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fileread.h"

void get_name(const char *line, char* name) //��ÿ����Ϣ�н�ȡ����
{
    int i = 0;
    memset(name, 0, 30);
    for(i = 0; line[i] != '\0'; i++)
    {
        if(line[i] == ',')
        {
            name[i] = '\0';
            break;
        }
        name[i] = line[i];
    }
}

PNode read_file(const char *filename, PNode head) //���ļ��ж�ȡ���ݲ�����������
{
    FILE* fin = NULL;
    char line[100] = {0};
    char name[30] = {0};

    fin = fopen(filename, "rt");
    if(fin == NULL)
    {
        printf("%s �ļ���ʧ��!\n", filename);
        return NULL;
    }

    while(!feof(fin))
    {
        fscanf(fin, "%s", line);
        get_name(line, name);
        printf("name: %s\n", name);
        memset(line, 0, 100);
    }

    return NULL;
}