#include <iostream>
using namespace std;

class node
{
public:
    int val;
    node *next;
    // constructor
    node(int d)
    {
        this->val = d;
        this->next = NULL;
    }
};

int ListToIntegers(node *head)
{
    int result = 0;

    node *curr = head;
    while (curr != NULL)
    {
        result = result * 10 + curr->val;
        curr = curr->next;
    }
    return result;
}

int reverse(int x)
{
    int reverseX = 0;
    while (x != 0)
    {
        int digit = x % 10;
        reverseX = reverseX * 10 + digit;
        x /= 10;
    }
    return reverseX;
}

node* intToLinkedList(int num){
    node* head = NULL;
    node* curr = NULL;

    while( num > 0){
        int digit = num % 10;
        node* temp = new node(digit);

        if(head == NULL){
            head = temp;
            curr = temp;
        }else{
            curr -> next = temp;
            curr = temp;
        }
        num /= 10;
    }
    return head;
}

void print(node* &head) {
    while (head != nullptr) {
        std::cout << head->val << " ";
        head = head->next;
    }
    std::cout << std::endl;
}

int sum(int integer1, int integer2){
    int sum;
    sum = integer1 + integer2;
    return sum;
}

int main()
{
    
    node *l1 = new node(2);
    l1 ->next = new node(4);
    l1 ->next->next = new node(3);
    // cout << "linked list 1: " << " ";
    // print(node1);
    
    node *l2 = new node(5);
    l2->next = new node(6);
    l2->next->next = new node(4);
    // cout << "linked list 2: " << " ";
    // print(node2);

    int integer1 = ListToIntegers(node1);
    cout << "integer 1: " << integer1 << endl;
    int integer2 = ListToIntegers(node2);
    cout << "integer 1: "<< integer2 << endl;
    int sum = integer1 + integer2;
    cout << "Sum :" << sum << endl;
    int reversed = reverse(sum);
    cout << "reversed sum : " << reversed << endl;
    node* linkedList = intToLinkedList(reversed);
    cout << " final linked list is :" << " ";
    print(linkedList);
}
