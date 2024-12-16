#include <iostream>

using namespace std;

int c[100];
int size = 0;

int main(){
    
    int a[] = {1,2,3};
    int b = 4;
    int c = 5;
    int d = 6;
    
    int* p = new int(2);
    *p = 5;
    delete p;
    
    c[0] = 4; size++;
    c[1] = 5; size++;
    c[2] = 6; size++;
    
    
    cout << a << endl;
    cout << &a[1] << endl;
    cout << &a[2] << endl;
    cout << &b << endl;
    cout << &d << endl;
    cout << &b << endl;


    cout << a[0] << endl;
    cout << *(a-2) << endl;
    
    return 0;
}