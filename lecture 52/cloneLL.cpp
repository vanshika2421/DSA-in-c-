#include<iostream>
using namespace std;

Node* copyList(Node* head){
    Node* clonehead = NULL;
    Node* clonetail = NULL;

    Node* temp = head;
    while(temp != NULL){
        insertAttail(clonehead, clonetail, temp -> data);
        temp = temp -> next;
    }
    // step 2: add pointers to clone list pof original list (to avoid mapping)

    Node* originalNode = head;
    Node* cloneNode = clonehead;

    while(originalNode != null){
        Node* forward =  originalNode -> next; 
        originalNode -> next = cloneNode;
        originalNode = forward;

        forward = cloneNode -> next;
        cloneNode -> next = originalNode;
        cloneNode = forward;
    }

    temp = head;
    while(temp){
        if(temp -> next){
            if(temp-> arb){
                temp -> next -> random = temp-> random -> next;
            }
            else{
                temp -> next = temp -> random
             }
        }
    }

    originalNode = head;
    cloneNode = clonehead;

    while(originalNode != null){
        originalNode -> next = cloneNode -> next;
        originalNode = originalNode -> next;

        cloneNode -> next = original -> next;
        cloneNode = cloneNode- > next;
    }

}
