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
        int len1 = getLength(l1);
        int len2 = getLength(l2);

        if (len1 < len2) {
            l1 = padList(l1, len2 - len1);
        } else {
            l2 = padList(l2, len1 - len2);
        }

        Pair sum = addListsHelper(l1, l2);

        if (sum.carry == 0) {
            return sum.node;
        } else {
            ListNode* result = new ListNode(sum.carry);
            result->next = sum.node;
            return result;
        }
    }

private:
    struct Pair {
        ListNode* node;
        int carry;
        Pair(ListNode* n, int c) : node(n), carry(c) {}
    };

    Pair addListsHelper(ListNode* l1, ListNode* l2) {
        if (l1 == nullptr && l2 == nullptr) {
            return Pair(nullptr, 0);
        }

        Pair result = addListsHelper(l1->next, l2->next);
        int value = result.carry + l1->val + l2->val;
        ListNode* fullResult = new ListNode(value % 10);
        fullResult->next = result.node;
        return Pair(fullResult, value / 10);
    }

    int getLength(ListNode* node) {
        int length = 0;
        while (node) {
            length++;
            node = node->next;
        }
        return length;
    }

    ListNode* padList(ListNode* node, int padding) {
        for (int i = 0; i < padding; i++) {
            ListNode* head = new ListNode(0);
            head->next = node;
            node = head;
        }
        return node;
    }
};



/*
pair 
node
carry
pair(int c){
    this-> carry = c;
    this-> n = NULL;
}


*/
