#ifndef LIST_H_
#define LIST_H_
#include "head.h"
PNode ListInit(SDataType data); //��ʼ��������
PNode ListAddEnd(PNode head, SDataType data); //��β��׷�ӽ��
PNode ListFindNode(PNode head, char *key); //���ҽ��
PNode ListInsertNode(PNode head, char *findkey, SDataType data); //��ָ��λ�ò�����
PNode ListMergeNode(PNode head, SDataType data); //�ϲ��������㣬ͳ�Ƶ�¼����
int ListDeleteNode(PNode head, char* name); //ɾ��ָ�����
int ListLength(PNode head); //���㵥������
void ListAllNode(PNode head); //�������н��
void ListDestory(PNode head); //���ٵ�����
#endif //LIST_H_