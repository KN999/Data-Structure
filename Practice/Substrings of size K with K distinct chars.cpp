#include<iostream>
#include<vector>
#include<map>
#include<bits/stdc++.h>
#include<algorithm>
#include<set>
#include<string.h>
using namespace std;

class Solution {
public:
    vector<string> solve(string str, int k) {
        
        vector<string> result;
        set<string> res;
        // string curr = "";
        // set<char> s;
        // set<string> res;
        // vector<string> result;

        // for(int i=0; i<k; i++) {
        //     curr += str[i];
        //     s.insert(str[i]);

        //     if(s.size() == k)
        //         res.insert(curr);
        // }

        // for(int i=k; i<str.size(); i++) {
        //     if(s.size() == k)
        //         s.erase(curr[0]);
        //     curr.erase(0, 1);
        //     curr += str[i];
        //     s.insert(str[i]);

        //     if(s.size() == k)
        //         res.insert(curr);
        // }

        for(int i=0; i<str.size(); i++) {
            string curr = str.substr(i, k);
            set<char> s(curr.begin(), curr.end());

            if(s.size() == k)
                res.insert(str.substr(i, k));
        }

        for(auto sub : res)
            result.push_back(sub);

        return result;
    }
};

int main()
{

    string s = "abacab";
    int k = 3;

    //cin>>s>>k;

    Solution S;
    vector<string> result = S.solve(s, k);

    for(auto res : result) {
        cout<<res<<" ";
    }

    cout<<endl;

    return 0;
}
