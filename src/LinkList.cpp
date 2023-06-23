// 2023/6/20

#include <iostream>
#include "LinkList.h"

using std::cin;
using std::cout;
using std::endl;

bool init(LinkList &L)
{
    if (L)
    {
        cout << "list is already initialized!" << endl;
        return false;
    }
    L = new LinkListNode;
    L->next = nullptr;
    return true;
}

bool empty(LinkList L)
{
    if (L)
    {
        return L->next == nullptr;
    }
    return true;
}

int length(LinkList L)
{
    if (empty(L))
    {
        return 0;
    }
    int len = 0;
    auto p = L->next;
    while (p != nullptr)
    {
        ++len;
        p = p->next;
    }
    return len;
}

bool head_insert(LinkList &L)
{
    if (!empty(L))
    {
        cout << "list is not empty!" << endl;
        return false;
    }
    if (!L)
    {
        init(L);
    }
    LinkListElemType e;
    cin >> e;
    while (e != 9999)
    {
        auto p = new LinkListNode;
        p->data = e;
        p->next = L->next;
        L->next = p;
        cin >> e;
    }
    return true;
}

bool tail_insert(LinkList &L)
{
    if (!empty(L))
    {
        cout << "list is not empty!" << endl;
        return false;
    }
    if (!L)
    {
        init(L);
    }
    LinkListElemType e;
    auto p_tail = L;
    cin >> e;
    while (e != 9999)
    {
        auto p = new LinkListNode;
        p->data = e;
        p->next = p_tail->next;
        p_tail->next = p->next;
        p_tail = p;
        cin >> e;
    }
    return true;
}

int locate_elem(LinkList L, LinkListElemType e)
{
    if (empty(L))
    {
        cout << "list is empty!" << endl;
        return 0;
    }
    // the first element's index = 1
    int index = 1;
    auto p = L->next;
    while (p->data != e)
    {
        ++index;
        p = p->next;
    }
    return index;
}

bool get_elem(LinkList L, int index, LinkListElemType &e)
{
    if (empty(L))
    {
        cout << "list is empty!" << endl;
        return false;
    }
    int i = 1;
    auto p = L->next;
    while (i != index && p)
    {
        p = p->next;
        ++i;
    }
    if (p)
    {
        e = p->data;
        return true;
    }
    return false;
}

bool list_insert(LinkList &L, int index, LinkListElemType e)
{
    if (index < 1 || index > length(L) + 1)
    {
        cout << "index is out of range!" << endl;
        return false;
    }
    int i = 1;
    auto p = L;
    while (i != index)
    {
        ++i;
        p = p->next;
    }
    auto p_new_node = new LinkListNode;
    p_new_node->data = e;
    p_new_node->next = p->next;
    p->next = p_new_node;
    return true;
}

bool list_delete(LinkList &L, int index, LinkListElemType &e)
{
    if (empty(L))
    {
        cout << "list is empty!" << endl;
        return false;
    }
    if (index < 1 || index > length(L))
    {
        cout << "index is out of range!" << endl;
        return false;
    }
    int i = 1;
    auto p = L;
    while (i != index)
    {
        ++i;
        p = p->next;
    }
    auto p_delete = p->next;
    p->next = p_delete->next;
    e = p_delete->data;
    delete p_delete;
    return true;
}

void print_list(LinkList L)
{
    if (empty(L))
    {
        cout << "list is empty!" << endl;
        return;
    }
    auto p = L->next;
    while (p)
    {
        cout << p->data << endl;
        p = p->next;
    }
}

bool init2(LinkList &L)
{
    if (L)
    {
        cout << "list is already initialized!" << endl;
        return false;
    }
    return true;
}

bool empty2(LinkList L)
{
    return L == nullptr;
}

int length2(LinkList L)
{
    if (empty2(L))
    {
        cout << "list is empty!" << endl;
        return false;
    }
    int len = 0;
    auto p = L;
    while (p)
    {
        ++len;
        p = p->next;
    }
    return len;
}

bool head_insert2(LinkList &L)
{
    if (L)
    {
        cout << "list is already created!" << endl;
        return false;
    }
    auto p_head = new LinkListNode;
    p_head->next = nullptr;
    LinkListElemType e;
    cin >> e;
    while (e != 9999)
    {
        auto p = new LinkListNode;
        p->data = e;
        p->next = p_head->next;
        p_head->next = p;
        cin >> e;
    }
    L = p_head->next;
    return true;
}

bool tail_insert2(LinkList &L)
{
    if (L)
    {
        cout << "list is already created!" << endl;
        return false;
    }
    auto p_head = new LinkListNode;
    auto p_tail = p_head;
    p_head->next = nullptr;
    LinkListElemType e;
    cin >> e;
    while (e != 9999)
    {
        auto p = new LinkListNode;
        p->data = e;
        p->next = p_tail->next;
        p_tail->next = p;
        p_tail = p;
        cin >> e;
    }
    L = p_head->next;
    return true;
}

int locate_elem2(LinkList L, LinkListElemType e)
{
    if (empty2(L))
    {
        cout << "link list is empty!" << endl;
        return 0;
    }
    auto p = L;
    int i = 1;
    while (p && p->data != e)
    {
        ++i;
        p = p->next;
    }
    if (p)
    {
        return i;
    }
    return 0;
}

bool get_elem2(LinkList L, int index, LinkListElemType &e)
{
    if (empty2(L))
    {
        cout << "link list is empty!" << endl;
        return 0;
    }
    auto p = L;
    int i = 1;
    while (p && i != index)
    {
        ++i;
        p = p->next;
    }
    if (p)
    {
        e = p->data;
        return true;
    }
    cout << "index is out of range!" << endl;
    return false;
}

bool list_insert2(LinkList &L, int index, LinkListElemType e)
{
    if (!L)
    {
        cout << "link list is not exist!" << endl;
        return false;
    }
    if (index < 1 || index > length2(L) + 1)
    {
        cout << "index is out of range!" << endl;
        return false;
    }
    int i = 1;
    auto p_head = new LinkListNode;
    p_head->next = L;
    auto p_pre = p_head;
    while (p_pre && i != index)
    {
        ++i;
        p_pre = p_pre->next;
    }
    if (p_pre)
    {
        auto p = new LinkListNode;
        p->data = e;
        p->next = p_pre->next;
        p_pre->next = p;
        L = p_head->next;
        return true;
    }
    return false;
}

bool list_delete2(LinkList &L, int index, LinkListElemType &e)
{
    if (empty2(L))
    {
        cout << "link list is empty!" << endl;
        return false;
    }
    if (index < 1 || index > length2(L))
    {
        cout << "index is out of range!" << endl;
        return false;
    }
    auto p_head  = new LinkListNode;
    p_head->next = L;
    int i = 1;
    auto p_pre = p_head;
    auto p = p_head->next;
    while (p && i != index)
    {
        ++i;
        p_pre = p_pre->next;
        p = p->next;
    }
    if (p)
    {
        p_pre->next = p->next;
        delete p;
        L = p_head->next;
        return true;
    }
    return false;
}

void print_list2(LinkList L)
{
    if (empty2(L))
    {
        cout << "list is empty!" << endl;
        return;
    }
    auto p = L;
    while (p)
    {
        cout << p->data << endl;
        p = p->next;
    }
}