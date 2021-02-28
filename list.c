#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"

PNode ListInit(SDataType data) //��ʼ��������
{
    PNode head = (PNode)malloc(sizeof(Node));
    if (head == NULL)
    {
        printf("�����ڴ�ʧ��!\n");
        return NULL;
    }
    head->_data = data;
    head->_PNext = NULL;

    return head;
}

PNode ListAddEnd(PNode head, SDataType data) //��β��׷�ӽ��
{
    PNode node, htemp;
    if(!(node = (PNode)malloc(sizeof(Node))))
    {
        printf("�����ڴ�ʧ��!\n");
        return head;
    }
    node->_data = data;
    node->_PNext = NULL;
    if (head == NULL)
    {
        head = node;
        return head;
    }
    htemp = head;
    while(htemp->_PNext != NULL)
    {
        htemp = htemp->_PNext;
    }
    htemp->_PNext = node;
    return head;
}

PNode ListFindNode(PNode head, char *key) //���ҽ��
{
    PNode htemp;
    htemp = head;
    while(htemp)
    {
        if(strcmp(htemp->_data.name, key) == 0)
        {
            return htemp;
        }
        htemp = htemp->_PNext;
    }
    return NULL;
}

PNode ListInsertNode(PNode head, char *findkey, SDataType data) //��ָ��λ�ò�����
{
    PNode node, nodetemp;
    if(!(node = (PNode)malloc(sizeof(Node))))
    {
        printf("�����ڴ�ʧ��!\n");
        return head;
    }
    node->_data = data;
    nodetemp = ListFindNode(head, findkey);
    if(nodetemp)
    {
        node->_PNext = nodetemp->_PNext;
        nodetemp->_PNext = node;
    } else {
        printf("δ�ҵ���ȷ�Ĳ���λ��!\n");
        free(node);
    }
    return head;
}

PNode ListMergeNode(PNode head, SDataType data) //�ϲ��������㣬ͳ�Ƶ�¼����
{
    PNode node, nodetemp;
    nodetemp = ListFindNode(head, data.name);
    if(nodetemp)
    {
        nodetemp->_data.totalcount++;
    } else {
        if(!(node = (PNode)malloc(sizeof(Node))))
        {
            printf("�����ڴ�ʧ��!\n");
            return head;
        }
        node->_data = data;
        node->_PNext = nodetemp->_PNext;
        nodetemp->_PNext = node;
    }
    return head;
}

int ListDeleteNode(PNode head, char* name) //ɾ��ָ�����
{
    PNode node, htemp;
    htemp = head;
    node = head;
    while(htemp)
    {
        if(strcmp(htemp->_data.name, name) == 0)
        {
            node->_PNext = htemp->_PNext;
            free(htemp);
            return 1;
        } else {
            node = htemp;
            htemp = htemp->_PNext;
        }
    }
    return 0;
}

int ListLength(PNode head) //���㵥������
{
    PNode htemp;
    int len = 0;
    htemp = head;
    while(htemp)
    {
        len++;
        htemp = htemp->_PNext;
    }
    return len;
}

void ListAllNode(PNode head) //�������н��
{
    PNode htemp;
    if(head == NULL)
    {
        printf("����Ϊ��!\n");
        return;
    }
    htemp = head;
    printf("��ǰ������%d����㡣���������������£�\n", ListLength(head));
    while(htemp)
    {
        printf("%s, %d\n", htemp->_data.name, htemp->_data.totalcount);
        htemp = htemp->_PNext;
    }
}

void ListDestory(PNode head) //���ٵ�����
{
    PNode nodetemp;
    while(head)
    {
        nodetemp = head;
        head = head->_PNext;
        free(nodetemp);
    }
}