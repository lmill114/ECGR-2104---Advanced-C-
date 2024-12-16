#include <iostream>   // Layton Miller      3/16/23         ECGR 2104 Project 5
#include "doubly_linked_list.h"
#include "doubly_linked_list.cpp"
using namespace std;


void test(){
    DoublyLinkedList dll;
    
    dll.push(1);
    dll.push(2);
    dll.push(3);
    
    DoublyLinkedList dllCopy = dll;
    
    dllCopy.push(4);
    dllCopy.remove(1);
    dllCopy.remove(0);
    dllCopy.insert(5, 1);
    
    dll.print();
    dllCopy.print();
   
    dll = dllCopy;
    dll.print();
    
}

int main(){
    test();
    
    return 0;
}