#ifndef HEAD_H_
#define HEAD_H_
#define LENGTH 30
typedef struct User_login {
    char name[LENGTH];  //�û���
    int totalcount;     //��¼����
} SDataType;    //����ڵĵ�
typedef struct SListNode {
    SDataType _data;
    struct SListNode* _PNext;
}Node, *PNode;  //��װ����ڵ��nextָ��

#endif //HEAD_H_