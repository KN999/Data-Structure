#include<iostream>
#include<bits/stdc++.h>
using namespace std;

string solve(int arr[], int N) {
    unordered_set<int> s;
    int prefix = 0;

    for(int i=0; i<N; i++) {
        prefix += arr[i];

        if(prefix == 0 || s.find(prefix) != s.end())
            return "Yes";
        else
            s.insert(prefix);
    }

    return "No";

}

int main() {
    int T;
    cin>>T;

    while(T--) {
        int N;
        cin>>N;

        int arr[N];
        for(int i=0; i<N; i++)
            cin>>arr[i];

        string result = solve(arr, N);
        cout<<result<<endl;
    }

    return 0;
}
