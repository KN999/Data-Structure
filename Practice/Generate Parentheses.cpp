#include<iostream>
#include<vector>
#include<map>
#include<bits/stdc++.h>
#include<algorithm>
#include<set>
#include<string.h>
using namespace std;

class Solution {
    vector<string> result;
public:
    vector<string> solve(int n) {
        backtrack("", 0, 0, n);
        return result;
    }

    void backtrack(string cur, int open, int close, int max) {
        if(cur.size() == 2*max) {
            result.push_back(cur);
            return;
        }

        if(open < max)
            backtrack(cur+"(", open+1, close, max);
        if(close < open)
            backtrack(cur+")", open, close+1, max);
    }
};

int main()
{

    int n = 2;

    Solution S;
    vector<string> result = S.solve(n);

    for(auto res : result) {
        cout<<res<<" ";
    }

    cout<<endl;

    return 0;
}
