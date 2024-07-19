#include<iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node()
    {
        this->data = 0;
        next = NULL;
    }
    Node(int data)
    {
        this->data = data; 
        this->next = NULL;
    }
    Node(int data, Node* next)
    {
        this->data = data;
        this->next = next;
    }
};

void insertAttail(Node* &tail, Node* curr){
    tail-> next = curr;
    tail = curr;
}

Node* sortList(Node *head){
    Node* zerohead = new Node(-1);
    Node* zerotail = zerohead;
    Node* onehead = new Node(-1);
    Node* onetail = onehead;
    Node* twohead = new Node(-1);
    Node* twotail = twohead;

    Node* curr = head;
    
    
    while(curr != NULL){
        int value = curr-> data;
        if(value == 0){
            insertAttail(zerotail, curr);
        }
        else if(value == 1){
            insertAttail(onetail, curr);
        }
        else if(value == 2){
            insertAttail(twotail, curr);
        }
        curr = curr-> next;
    }

    // curr = head;
    
        if(onehead -> next != NULL){
            zerotail-> next = onehead-> next;
        }
        else{
        zerotail-> next = twohead-> next;
        }
        onetail -> next = twohead -> next;
        twotail -> next = NULL;
        
        head = zerohead -> next;
        delete zerohead;
        delete onehead;
        delete twohead;

        return head;

}