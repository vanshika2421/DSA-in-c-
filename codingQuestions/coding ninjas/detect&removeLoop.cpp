#include<iostream>
#include<map>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    //constructor
    Node(int d){
        this-> data = d;
        this-> next = NULL;
    }
    ~Node(){
        int value = this-> data;
        if(this-> next != NULL){
            delete next;
            next = NULL;
        }
        cout << " deleted value is: " << value << endl; 
    }
};


void insertNode(Node* &tail, int element, int d){
    // empty list
    if(tail == NULL){
        Node* newNode  = new Node(d);
        tail = newNode;
        newNode -> next = newNode;
    }
    else{
        Node* temp = new Node(d);
        Node* curr = tail;
        // curr -> next = temp;
        // Node* forward = curr -> next;
        // temp -> next = forward;
        while(curr -> data != element){
            curr = curr-> next;
        } 
        // Node* temp = new Node(d);
        temp-> next = curr-> next;
        curr-> next = temp;
    }
} 

void print(Node* tail){
    Node* temp = tail;
    cout << tail -> data  << " ";
    while(tail-> next != temp){
        cout<< tail-> data << " ";
        tail = tail -> next;
    }
    cout << endl;

    // OR
    // Node* temp = tail;
    // do{
    //     cout << tail-> data << endl;
    //     tail = tail-> next;
    // }while(tail != temp);
}



Node* floydDetection(Node* &head){
    if(head == NULL){
        return NULL;
    }
    Node* slow = head;
    Node* fast = head;

    while(slow && fast){ // this means jab tk dno null na hojaye
    slow = slow-> next;
    fast = fast -> next -> next;
    if(slow ==fast){
        cout << "present at : " << slow -> data << endl;
        return slow;
    }
    }
    return NULL;
}

Node* getStartingNode(Node* &head){
    if(head == NULL){
        return NULL;
    }
    Node* intersection = floydDetection(head);
    Node* slow  = head;

    while(slow != intersection){
        slow = slow -> next;
        intersection = intersection -> next;
    }
    return slow;
}

void removeLoop(Node* head){
    if(head == NULL){
        return;
    }
    Node* startOfLoop = getStartingNode(head);
    Node* temp = startOfLoop;

    while(temp -> next != startOfLoop){
        temp = temp -> next;
    }
    temp -> next = NULL;
}

int main()
{
    Node* tail = NULL;
    // insertNode(tail,3, 3);
    // print(tail);
    insertNode(tail,-1,45);
    print(tail);
    insertNode(tail,45, 7);
    print(tail);
    // insertNode(tail, 5, 6);
    // print(tail);
    insertNode(tail, 7,8);
    print(tail);
    insertNode(tail,8,11);
    print(tail);
    // deleteNode(tail, 6);
    // print(tail);
     insertNode(tail,11,9);
    print(tail);
    insertNode(tail,9,14);
    print(tail);
    insertNode(tail,14,8);
    print(tail);

    if(floydDetection(tail)){
        cout << "cycle is present" << endl;
    }
    else{
        cout << "cycle is not present" << endl;
    }

Node* loopPoint = getStartingNode(tail);
cout << "loop is starting at : " << loopPoint -> data << endl;
removeLoop(tail);
cout << "loop is starting at : " << loopPoint -> data << endl;
}


 