#include <iostream>

using namespace std;

template<typename T>
class MyVector{
    public:
    MyVector(){
        nextIdx = 0;
        arraySize = 3;
        a = new T[arraySize];
    }
    
    MyVector(const MyVector& rhs){
        cout << "Copy Constructor called!" << endl;
        nextIdx = rhs.nextIdx;
        arraySize = rhs.arraySize;
        
        a = new T[arraySize];
        for(int j = 0; j < nextIdx; j++){
            a[j] = rhs.at(j);
        }
    }
    
    ~MyVector(){
        cout << "Destructor called!" << endl;
        delete a;
    }
    
    void operator=(const MyVector& rhs){
        cout << "Assignment operator override called!" << endl;
        delete[] a;
        
        nextIdx = rhs.nextIdx;
        arraySize = rhs.arraySize;
        
        a = new T[arraySize];
        for(int j = 0; j < nextIdx; j++){
            a[j] = rhs.at(j);
        }
    }
    
    void push_back(T val){
        if(nextIdx == arraySize){
            cout << "Reallocating more space" << endl;
            int* temp = new T[arraySize*2];
            for (int i = 0; i < arraySize; i++)
                temp[i] = a[i];
            delete[] a;
            a = temp;
            arraySize = arraySize*2;
            }
        
        a[nextIdx] = val;
        nextIdx++;
    }
    
    T& at(T idx) const{
        return a[idx];
    }
    
    T size(){
        return nextIdx;
    }
    
    void pop_back(){
        nextIdx--;
    }
    
    int* a;
    private:
    
    int nextIdx;
    int arraySize;
};

void makesProblem(){
    
    MyVector<int> v;
   
    v.push_back(10);
    v.push_back(8);
    v.push_back(5);
    v.push_back(7);
    v.push_back(10);
    v.push_back(8);
    v.push_back(5);
    v.push_back(7);
    
    v.pop_back();
    v.pop_back();
    
    v.push_back(20);
    
    MyVector<int> v2;
    v.push_back(10);
    v.push_back(8);
    v.push_back(5);
    v.push_back(7);
    
    v2 = v;
    
    for(int i = 0; i < v2.size(); i++){
        cout << v2.at(i) << endl;
    }
    
    MyVector<int> v3 = v;
}

int main(){
    
    makesProblem();
    
    makesProblem();
    
    makesProblem();
    
    return 0;
}