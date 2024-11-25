//
//  main.cpp
//  Linked-List-C++
//
//  Created by MEDLAO on 18/11/2024.
//

#include <iostream>
using namespace std;


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
    
    //Function to insert a new node at a specific position in the list
    void insertAtPosition(int value, int position)
    {
        if (position < 1) {
            cout << "Position should be >= 1." << endl;
            return;
        }
        
        if (position == 1) {
            insertAtBeginning(value);
            return;
        }
        
        Node* newNode = new Node();
        newNode->data = value;
        
        //Traverse to the node before the desired position
        Node* temp = head;
        for (int i = 1; i < position - 1 && temp; ++i) {
            temp = temp->next;
        }
        
        //If the position is out of range, print an error message
        if (!temp) {
            cout << "Position out of range." << endl;
            delete newNode;
            return;
        }
        
        //Insert the new node at the desired position
        newNode->next = temp->next;
        temp->next = newNode;
    }
    
    //Function to delete the first node of the list
    void deleteFromBeginning()
    {
        if (!head) {
            cout << "List is empty." << endl;
            return;
        }
        
        Node* temp = head;
        head = head->next;
        delete temp;
    }
    
    //Function to delete the last node of the list
    void deleteFromEnd()
    {
        if (!head) {
            cout << "List is empty." << endl;
            return;
        }
        
        if (!head->next) {
            delete head;
            head = NULL;
            return;
        }
        
        //Traverse to the second-to-last node
        Node* temp = head;
        while (temp->next->next) {
            temp = temp->next;
        }
        
        //Delete the last node
        delete temp->next;
        //Set the second-to-last node's next to NULL
        temp->next = NULL;
        
    }
    
    //Function to delete a node at a specific postion from the list
    void deleteFromPosition(int position)
    {
        if (position < 1) {
            cout << "Position should be >= 1." << endl;
            return;
        }
        
        if (position == 1) {
            deleteFromBeginning();
            return;
        }
        
        Node* temp = head;
        for (int i = 1; i < position - 1 && temp; ++i) {
            temp = temp->next;
        }
        
        if (!temp || !temp->next) {
            cout << "Possition out of range." << endl;
            return;
        }
        
        //Save the node to be deleted
        Node* nodeToDelete = temp->next;
        //Update the next pointer
        temp->next = temp->next->next;
        //Delete the node
        delete nodeToDelete;
    }
    
    
};


int main(int argc, const char * argv[]) {
    // insert code here...
    
    return 0;
}
