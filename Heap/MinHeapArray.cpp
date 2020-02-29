#include <iostream>
#include <vector>
#include "heap.h"

using namespace std;

int main()
{
    MinHeapArray *m = new MinHeapArray;

    for(int i=5; i>=0; i--)
        m->push(i);
    
    cout<<"heap after insertion : "<<endl;
    m->print();

    cout<<"top : "<<m->top()<<endl;
    m->pop();
    cout<<"top : "<<m->top()<<endl;
    m->pop();
    cout<<"top : "<<m->top()<<endl;

    cout<<"\nheap after deletion : "<<endl;
    m->print();

    return 0;
}