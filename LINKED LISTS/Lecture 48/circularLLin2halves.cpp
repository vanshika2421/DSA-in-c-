#include <iostream>

struct Node {
    int data;
    Node* next;
    Node(int x) : data(x), next(nullptr) {}
};

// Function to insert a new node at the end of a circular linked list
void insert(Node*& head, int value) {
    Node* newNode = new Node(value);
    if (!head) {
        head = newNode;
        head->next = head; // Point to itself to make it circular
    } else {
        Node* temp = head;
        while (temp->next != head) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->next = head;
    }
}

// Function to divide a circular linked list into two halves
void divideCircularLL(Node* head, Node*& firstHalf, Node*& secondHalf) {
    if (!head || !head->next) {
        firstHalf = head;
        secondHalf = nullptr;
        return;
    }

    Node* slow = head;
    Node* fast = head->next;

    while (fast != head && fast->next != head) {
        slow = slow->next;
        fast = fast->next->next;
    }

    // Split the list into two halves
    firstHalf = head;
    secondHalf = slow->next;

    // Close the first half
    slow->next = head;

    // Find the end of the second half
    Node* tempFirstHalf = secondHalf;
    while (tempFirstHalf->next != head) {
        tempFirstHalf = tempFirstHalf->next;
    }

    // Close the second half
    tempFirstHalf->next = secondHalf;
}

// Function to print a circular linked list
void printCircularLL(Node* head) {
    if (!head) {
        return;
    }

    Node* temp = head;
    do {
        std::cout << temp->data << " ";
        temp = temp->next;
    } while (temp != head);

    std::cout << std::endl;
}

int main() {
    Node* head = nullptr;
    Node* firstHalf = nullptr;
    Node* secondHalf = nullptr;

    // Insert nodes into the circular linked list
    insert(head, 1);
    insert(head, 2);
    insert(head, 3);
    insert(head, 4);
    insert(head, 5);
    insert(head, 6);

    std::cout << "Original Circular Linked List: ";
    printCircularLL(head);

    // Divide the circular linked list into two halves
    divideCircularLL(head, firstHalf, secondHalf);

    std::cout << "First Half: ";
    printCircularLL(firstHalf);

    std::cout << "Second Half: ";
    printCircularLL(secondHalf);

    // Clean up memory (free allocated nodes)
    while (head) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}
