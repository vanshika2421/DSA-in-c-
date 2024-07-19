#include<iostream>
#include<map>
#include<algorithm>
#include<vector>

using namespace std;

class node{
    public:
    int data;
    node* next;

    node(int data){
        this -> data = data;
        this -> next = NULL;
    }
    ~node(){
        int value = this -> data;
        if(this->next != NULL){
            delete next;
            this-> next = NULL;
        }
        // cout << value << " <- this node is deleted" << endl;
    }    
    };

void insertAtHead(node* &head, int data){
    node* temp= new node(data);
    // |   | <- temp   |   | -> head
    temp -> next = head;
    head = temp;
}

void print(node* &head){
    node* temp = head;
    while(temp != NULL){
        cout << temp -> data << " ";
        temp = temp-> next;
    }
    cout << endl;
}

void insertAtTail(node* &tail, int data){
    node* temp = new node(data);
    tail -> next = temp;
    tail = tail -> next;
}


void insertAtPosition(node* tail, node* &head, int position, int data){
    if(position == 1){
        insertAtHead(head, data);
    }

    node* temp = head;
    int cnt = 1;
    while(cnt < position -1){
        temp = temp -> next;
        cnt++;
    }

    if(temp -> next == NULL){
        insertAtTail(tail, data);
    }
    node* nodeToInsert = new node(data);
    nodeToInsert -> next = temp -> next;
    temp -> next = nodeToInsert;
}
// APPROACH 1
// node* RemoveDuplicates(node* &head){
//     if( head == NULL){
//         return NULL;
//         cout << " list is empty. No duplicates found";
//     }
//     node* curr = head;
//     while(curr != NULL){
//         node* temp = curr;
//         while(temp -> next != NULL){
//             if(curr -> data == temp ->next -> data){
//                 node* duplicate = temp ->next;
//                 temp ->next= temp -> next -> next;
//                 // temp -> next = NULL;
//                 delete duplicate;
//             }
//             else{
//                 temp = temp -> next;
//             }
//         }
//             curr = curr -> next;
//     }
// return head;
// }

// APPROACH 2
// bool removeDuplicates(node* &head){
//     if(head == NULL){
//          return false;
//     }
    
//     node* curr = head;
//     map <node*, bool> visited;
//     while(curr != NULL){
//         if(visited[curr] == true){
//             curr = curr-> next;why 
//         }
//         visited[curr] = true;
//         curr = curr -> next;
//         curr-> next = curr-> next -> next;
//         curr -> next = NULL;
//         delete(curr -> next);
//     } 
    
//     return false;
// }

node* sortLinkedList(node* head){
    if( head == NULL){
        return NULL;
    }
    vector<int> values;
    while(head != NULL){
        values.push_back(head -> data);
        head = head-> next;
    }
    sort(values.begin(), values.end());

    node dummy(0);
    node* curr = &dummy;
    for(int value : values){
        curr-> next = new node(value);
        curr = curr-> next;
    }
    return dummy.next;
}

node* removeDuplicates(node* head){
    head = sortLinkedList(head);
    node* curr = head;
    while(curr != NULL && curr->next !=  NULL){
        if(curr -> data == curr -> next -> data){
            node* duplicate = curr -> next;
            curr -> next = curr -> next -> next;
            delete duplicate;
        }else{
            curr= curr-> next;
        }  
    } 
    return head;
} 


int main(){
    node* node1 = new node(10);
    node* head = node1;
    node* tail = node1;
    insertAtHead(head, 34);
    print(head);
    // cout << endl;
    insertAtTail(tail, 56);
    print(head);
    insertAtPosition(tail, head, 2, 33);
    print(head);
    insertAtPosition(tail, head, 3, 33);
    print(head);
    head = sortLinkedList(head);
    head =removeDuplicates(head);
    print(head);

    while (head) {
        node* temp = head;
        head = head->next;
        delete temp;
    }
}

