//
//  main.cpp
//  Linked-List-C++
//
//  Created by MEDLAO on 18/11/2024.
//

#include <iostream>


//Structure for a node in the linked list
struct Node {
    int data; // The value stored in the node
    Node* next; // Pointer to the next node
};

//Define a the linked list class
class LinkedList {
    Node* head;
    
public:
    //Constructor initializes head to NULL
    LinkedList() : head(NULL) {}
    
    //Function to insert a new node at the beginning of the list
    void insertAtBeginning(int value) {
        Node* newNode = new Node();
        newNode->data = value;
        newNode->next = head;
        head = newNode;

    }
    
    //Function to insert a new node at the end of the list
    void insertAtEnd(int value) {
        Node* newNode = new Node();
        newNode->data = value;
        newNode->next = NULL;
        
        //If the list is empty, update the head to the new node
        if (!head) {
            head = newNode;
            return;
        }
        
        //Traverse to the last node
        Node* temp = head;
        while (temp->next) {
            temp = temp->next;
        }
        
        //Update the last node's next to the new node
        temp->next = newNode;
    }
    
};


int main(int argc, const char * argv[]) {
    // insert code here...
    
    return 0;
}
