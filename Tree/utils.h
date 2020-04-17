#include <iostream>

void Print(vector<int> v) {

    for(auto num : v) 
        cout<<num<<" ";

    cout<<endl;
}

void Print(vector<vector<int>> v) {

    for(auto nums : v) {
        Print(nums);
    }

    cout<<endl;
}