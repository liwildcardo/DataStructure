// 2023/6/20

#include <iostream>
#include "LinkList.h"
#include "solution2.h"

using namespace std;

int main()
{
    LinkList L = nullptr;
    init2(L);
    tail_insert2(L);
    print_list2(L);
    solution01(L, 1);
    cout << "after solution01" << endl;
    print_list2(L);

    return 0;
}