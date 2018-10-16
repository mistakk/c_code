#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <iostream>
#include <sstream>
#include <queue>
#include <set>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL){};
};
ListNode *insertionSortList(ListNode *head)
{
    if(head==NULL) return NULL;
    ListNode *ret = head, *p, *tail;
    head = head->next;
    ret->next = NULL;
    while (head != NULL)
    {
        p = head;
        head = head->next;
        //insert p to ret.
        if (p->val < ret->val)
        {
            p->next = ret;
            ret = p;
        }
        else
        {
            tail = ret;
            while (tail->next != NULL && tail->next->val < p->val)
                tail = tail->next;
            p->next = tail->next;
            tail->next = p;
        }
    }
    return ret;
}
int main()
{
    ListNode *t1 = (ListNode *)malloc(sizeof(ListNode));
    ListNode *t2 = (ListNode *)malloc(sizeof(ListNode));
    ListNode *t3 = (ListNode *)malloc(sizeof(ListNode));
    ListNode *t4 = (ListNode *)malloc(sizeof(ListNode));
    t1->val = 4;
    t2->val = 2;
    t3->val = 1;
    t4->val = 5;
    t1->next = t2;
    t2->next = t3;
    t3->next = t4;
    t1 = insertionSortList(t1);
    // while (t1 != NULL)
    // {
    //     cout << t1->val << endl;
    //     ListNode *t2 = t1->next;
    //     free(t1);
    //     t1 = t2;
    // }
    return 0;
}