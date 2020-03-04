#include<iostream>
#include<vector>
#include<map>
#include<bits/stdc++.h>
#include<algorithm>
#include<set>
#include<string.h>
#include<iomanip>
#include <stdio.h> 
using namespace std;

class Solution
{
public:
    int longestConsecutive(vector<int>& nums) {
        set<int> s(nums.begin(), nums.end());
        int length = s.size();

        if(length < 2)
            return length;

        auto it = s.begin();
        int last = *it;
        it++;
        int count = 1;
        int Max = 1;

        for(; it!=s.end(); it++) {
            int cur = *it;

            if(cur-last == 1) {
                count++;
            }
            else {
                count = 1;
            }

            last = cur;
            Max = max(Max, count);
        }

        return Max;
    }
};

int main()
{
    vector<int> nums({100, 4, 200, 1, 3, 2});

    Solution S;
    int results = S.longestConsecutive(nums);
    
    cout<<results<<endl;

    return 0;
}