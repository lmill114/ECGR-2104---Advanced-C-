#include "doubly_linked_list.h"
    
    
    DoublyLinkedList::DoublyLinkedList(const DoublyLinkedList& rhs){
        cout << "Copy constructor called" << endl;
        head = nullptr;
        for(int i = 0; i < rhs.size(); i++){
            push(rhs.at(i));
        }
    }
    
    void DoublyLinkedList::operator=(const DoublyLinkedList& rhs){
        cout << "Copy assignment override called" << endl;
        //free the original list
        while(head != nullptr){
            Node* temp = head->next;
            delete head;
            head = temp;
        }
        //copy rhs list
        for(int i = 0; i < rhs.size(); i++){
            push(rhs.at(i));
        }
        
    }
    
    DoublyLinkedList::~DoublyLinkedList(){
        cout << "Destructor called" << endl;
        
        while(head != nullptr){
            Node* temp = head->next;
            delete head;
            head = temp;
        }
        
    }
    
    void DoublyLinkedList::push(int new_data){
        Node* new_node = new Node();
        
        new_node->data = new_data;
        new_node->next = nullptr;
        
        
        
        if(tail == nullptr){
            tail = new_node;
            tail->previous = nullptr;
            head = tail;
            return;
        }
        
        
        
        Node* currentNode = tail;
        tail->next = new_node;
        tail = tail->next;
        tail->next = nullptr;
        tail->previous = currentNode;
        
        return;                    
    }
    
    void DoublyLinkedList::pop(){
        Node* currentNode = tail;
    
        if(tail == nullptr){
            return;
        }
    
        if(currentNode->next == nullptr){
            delete tail;
            tail = nullptr;
            return;
        }
    
        while(currentNode->next->next != nullptr){
            currentNode = currentNode->next;
        }
    
        delete currentNode->next;
        currentNode->next = nullptr;
    }
    
    int DoublyLinkedList::size() const{
        int count = 0;
        Node* currentNode = head;
        while(currentNode != nullptr){
            currentNode = currentNode->next;
            count++;
        }
        
        return count;
    }
    
    void DoublyLinkedList::print(){
        int s = size();
        Node* curNode = head;
        
        for(int i = 0; i < s; i++){
            cout << curNode->data << endl;      
            curNode = curNode->next;
        }
    }
    
    int& DoublyLinkedList::at(int idx) const{
        Node* currentNode = head;
        int j = 0;
        while(j < idx){
           currentNode = currentNode->next;
           j++;
        }
        return currentNode->data;
    }
    
    void DoublyLinkedList::insert(int data, int pos){
        Node* new_node = new Node;
        new_node->data = data;
        
        Node* currentNode = head;
            int j = 0;
            while(j < pos){
               currentNode = currentNode->next;
               j++;
            }
        
        if(pos == 0){
           new_node->previous = nullptr;
           head = new_node;
           new_node->next = currentNode;
        }
        
        else{
            Node* prev_node = currentNode->previous;
            new_node->next = prev_node->next;
            prev_node->next = new_node;
            if(new_node->next != nullptr){
                new_node->next->previous = new_node;
            }
        }
       
    }
    
    void DoublyLinkedList::remove(int pos){
        int s = size();
        Node* currentNode = head;
            int j = 0;
            while(j < pos){
               currentNode = currentNode->next;
               j++;
            }
            
        if(pos == 0){
            head = currentNode->next;
        }
        
        else if(pos == (s-1)){
            currentNode->previous->next = nullptr;
            tail = currentNode->previous;
        }
        
        else{
            currentNode->next->previous = currentNode->previous;
            currentNode->previous->next = currentNode->next;
        }
            
    }