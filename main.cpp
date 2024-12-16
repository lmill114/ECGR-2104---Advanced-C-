#include <iostream>

using namespace std;

/*void foo(int& z){
    z = 10;
}
*/
void foo(int* z){
    *z = 10;
}

int main(){
    int x = 500;
    char c = 'A';
    
    int* p = &x;
    char* p2 = &c;
    
    cout << *p << endl;
    cout << *p2 << endl;
    
    foo(p);
    // org++ main_array.cpp -o test
    foo(&x);
    
    cout << x << endl;
    cout << p << endl;
    
    return 0;
}