#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int solve(int arr[], int N, int sum) {
    unordered_map<int, int> m;
    int prefix = 0;
    int count = 0;

    for(int i=0; i<N; i++) {
        prefix += arr[i];

        if(prefix == sum)
            count++;
        if(m.find(prefix - sum) != m.end())
            count += m[prefix];

        m[prefix]++;
    }
    return count;
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
