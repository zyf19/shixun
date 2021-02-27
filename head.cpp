#ifndef HEAD_H_
#define HEAD_H_
#define LENGTH 30
typedef struct User_login {
    char name[LENGTH];  //用户名
    int totalcount;     //登录次数
} SDataType;    //链表节的点
typedef struct SListNode {
    SDataType _data;
    struct SListNode* _PNext;
}Node, *PNode;  //封装链表节点和next指针

#endif //HEAD_H_