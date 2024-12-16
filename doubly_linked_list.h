#ifndef DOUBLY_LINKED_LIST
#define DOUBLY_LINKED_LIST

#include <iostream>

using namespace std;

struct Node{
    int data;
    Node* next;
    Node* previous;
};

class DoublyLinkedList{
    public:
    
    DoublyLinkedList(){
        tail = nullptr;
        head = nullptr;
    }
    
    
    DoublyLinkedList(const DoublyLinkedList& rhs);
    
    void operator=(const DoublyLinkedList& rhs);
    
    /*~DoublyLinkedList();*/      //Destructor implemented throughout rest of program
    
    void push(int new_data);
    
    void pop();
    
    int size() const;
    
    void print();
    
    int& at(int idx) const;
    
    void insert(int data, int pos);
    
    void remove(int pos);
    
  
    private:
    Node* head;
    Node* tail;
};

#endif