#include <iostream>
using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
struct ListNode {
     int val;
     ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
    ListNode* sortList(ListNode* head) {
        ListNode dummyHead(0);
        dummyHead.next = head;
        ListNode* p = head;
        int length = 0;
        while (p) {
            ++length;
            p = p->next;
        }

        for (int size = 1; size < length; size <<= 1) {
            ListNode* cur = dummyHead.next;
            ListNode* tail = &dummyHead;

            while (cur) {
                ListNode* left = cur;
                ListNode* right = cut(left, size); // left->@->@ right->@->@->@...
                cur = cut(right, size); // left->@->@ right->@->@  cur->@->...

                tail->next = merge(left, right);
                while (tail->next) {
                    tail = tail->next;
                }
            }
        }
        return dummyHead.next;
    }

    ListNode* cut(ListNode* head, int n) {
        ListNode* p = head;
        while (--n && p) {
            p = p->next;
        }

        if (!p) return NULL;

        ListNode* next = p->next;
        p->next = NULL;
        return next;
    }

    ListNode* merge(ListNode* l1, ListNode* l2) {
        ListNode dummyHead(0);
        ListNode* p = &dummyHead;
        while (l1 && l2) {
            if (l1->val < l2->val) {
                p->next = l1;
                p = l1;
                l1 = l1->next;
            } else {
                p->next = l2;
                p = l2;
                l2 = l2->next;
            }
        }
        p->next = l1 ? l1 : l2;
        return dummyHead.next;
    }
};

int main()
{
    int n=0;
    cout<<"please input listnode num:\n"<<endl;
    cin>>n;
    if(n<=0)
    {
        cout<<"n is less 0"<<endl;
        return 0;
    }
    ListNode *p = NULL;
    ListNode *first = new ListNode(0);
    cout<<"input val"<<endl;
    cin>>first->val;
    first->next = NULL;
    p=first;
    while(--n)
    {
        ListNode *newNode = new ListNode(0);
        cout<<"input val"<<endl;
        cin>>newNode->val;
        //newNode->next = p;Ç°Ðò²åÈë
        //p = newNode;
        newNode->next = NULL;
        first->next = newNode;
        first = newNode;
    }
    //cout<<"now output the val:"<<endl;
    //while(p)
    //{
    //    cout<<p->val<<endl;
    //    p = p->next;
    //}

    Solution so;
    ListNode *tp = so.sortList(p);
    cout<<"now output the val:"<<endl;
    while(tp)
    {
        cout<<tp->val<<endl;
        tp = tp->next;
    }
    ListNode dummyNode(0);
    dummyNode.next = p;
    while(dummyNode.next)
    {
        ListNode *tp = dummyNode.next;
        dummyNode.next = dummyNode.next->next;
        delete tp;
        cout<<"~~~~~"<<endl;
    }
}
