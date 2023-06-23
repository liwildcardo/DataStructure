// 2023/6/21

#include "solution2.h"

void solution01(LinkList &L, LinkListElemType x)
{
    LinkListNode *p;
    if (!p)
    {
        return;
    }
    if (L->data == x)
    {
        p = L;
        L = L->next;
        free(p);
        solution01(L, x);
    }
    else
    {
        solution01(L->next, x);
    }
}