// 2023/6/20

#pragma once

#include "Basic.h"

typedef struct LinkListNode
{
    LinkListElemType data;
    LinkListNode *next;
} LinkListNode, *LinkList;

bool init(LinkList &L);

bool empty(LinkList L);

int length(LinkList L);

bool head_insert(LinkList &L);

bool tail_insert(LinkList &L);

int locate_elem(LinkList L, LinkListElemType e);

bool get_elem(LinkList L, int index, LinkListElemType &e);

bool list_insert(LinkList &L, int index, LinkListElemType e);

bool list_delete(LinkList &L, int index, LinkListElemType &e);

void print_list(LinkList L);


// link list without head node


bool init2(LinkList &L);

bool empty2(LinkList L);

int length2(LinkList L);

bool head_insert2(LinkList &L);

bool tail_insert2(LinkList &L);

int locate_elem2(LinkList L, LinkListElemType e);

bool get_elem2(LinkList L, int index, LinkListElemType &e);

bool list_insert2(LinkList &L, int index, LinkListElemType e);

bool list_delete2(LinkList &L, int index, LinkListElemType &e);

void print_list2(LinkList L);