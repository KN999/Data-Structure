#include<iostream>

int swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}