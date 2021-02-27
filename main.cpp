#include <stdio.h>
#include "list.h"
#include "fileread.h"
void test_list() 
{
    SDataType data = {"Ryan", 0};
    PNode head = ListInit(data);

    SDataType data2 = {"Jack", 2};
    head = ListAddEnd(head, data2);

    SDataType data3 = {"Ryan", 0};
    head = ListMergeNode(head, data3);

    ListAllNode(head);
    ListDestory(head);
    return;
}
int main()
{
    PNode head = NULL;
    test_list();

    head = read_file("user_login.txt", head);

    return 0;
}