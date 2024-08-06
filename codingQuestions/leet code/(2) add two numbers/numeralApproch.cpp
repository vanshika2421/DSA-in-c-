#include<iostream>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode dummyHead(0);
        ListNode* p = l1;
        ListNode* q = l2;
        ListNode* curr = &dummyHead;
        int carry = 0;
        
        while (p != nullptr || q != nullptr) {
            int x = (p != nullptr) ? p->val : 0;
            int y = (q != nullptr) ? q->val : 0;
            int sum = carry + x + y;
            carry = sum / 10;
            curr->next = new ListNode(sum % 10);
            curr = curr->next;
            if (p != nullptr) p = p->next;
            if (q != nullptr) q = q->next;
        }
        if (carry > 0) {
            curr->next = new ListNode(carry);
        }

        return dummyHead.next;
    }
};

/*
nyi node = dummyhead
int p = l1;
int q = l2;
curr = &dummyhead;
carry =0;
while(p&&q{
    x = p -> val;
    y = q -> val;
    sum = carry + x  + y;
    carry = sum /10;
    curr -> next = sum %10;
    curr = curr -> next;
    if(p){
        p -> next;
        q-> next
    }
    carry > 0{
        node* carry = new node(carry);
    }
    return dummyHead;


}


*/