#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"

PNode ListInit(SDataType data) //初始化单链表
{
    PNode head = (PNode)malloc(sizeof(Node));
    if (head == NULL)
    {
        printf("申请内存失败!\n");
        return NULL;
    }
    head->_data = data;
    head->_PNext = NULL;

    return head;
}

PNode ListAddEnd(PNode head, SDataType data) //从尾部追加结点
{
    PNode node, htemp;
    if(!(node = (PNode)malloc(sizeof(Node))))
    {
        printf("申请内存失败!\n");
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

PNode ListFindNode(PNode head, char *key) //查找结点
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

PNode ListInsertNode(PNode head, char *findkey, SDataType data) //从指定位置插入结点
{
    PNode node, nodetemp;
    if(!(node = (PNode)malloc(sizeof(Node))))
    {
        printf("申请内存失败!\n");
        return head;
    }
    node->_data = data;
    nodetemp = ListFindNode(head, findkey);
    if(nodetemp)
    {
        node->_PNext = nodetemp->_PNext;
        nodetemp->_PNext = node;
    } else {
        printf("未找到正确的插入位置!\n");
        free(node);
    }
    return head;
}

PNode ListMergeNode(PNode head, SDataType data) //合并单链表结点，统计登录次数
{
    PNode node, nodetemp;
    nodetemp = ListFindNode(head, data.name);
    if(nodetemp)
    {
        nodetemp->_data.totalcount++;
    } else {
        if(!(node = (PNode)malloc(sizeof(Node))))
        {
            printf("申请内存失败!\n");
            return head;
        }
        node->_data = data;
        node->_PNext = nodetemp->_PNext;
        nodetemp->_PNext = node;
    }
    return head;
}

int ListDeleteNode(PNode head, char* name) //删除指定结点
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

int ListLength(PNode head) //计算单链表长度
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

void ListAllNode(PNode head) //遍历所有结点
{
    PNode htemp;
    if(head == NULL)
    {
        printf("链表为空!\n");
        return;
    }
    htemp = head;
    printf("当前链表共有%d个结点。链表所有数据如下：\n", ListLength(head));
    while(htemp)
    {
        printf("%s, %d\n", htemp->_data.name, htemp->_data.totalcount);
        htemp = htemp->_PNext;
    }
}

void ListDestory(PNode head) //销毁单链表
{
    PNode nodetemp;
    while(head)
    {
        nodetemp = head;
        head = head->_PNext;
        free(nodetemp);
    }
}