#include <iostream>
#include <vector>
using namespace std;

void Print(vector<char> graph) {

    for(auto node : graph) {
        cout<<node<<" ";
    }

    cout<<endl;
}