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
    vector<int> solve(vector<int> &nums, int target) {
        map<int, int> m;
        vector<int> result;
        for(int i=0; i<nums.size(); i++) {
            if(m.find(target-nums[i]) != m.end()) {
                int index = m[target-nums[i]];
                result.push_back(index);
                result.push_back(i);
            }
            
            m[nums[i]] = i;
        }

        if(result.size() == 0)
            return vector<int>({-1,-1});
        
        return vector<int>({result[result.size()-2], result[result.size()-1]});
    }
};

int main()
{

    vector<int> nums = {20, 50, 40, 25, 30, 10};
    int target = 90;

    Solution S;
    vector<int> result = S.solve(nums, target-30);

    for(auto res : result) {
        cout<<res<<" ";
    }

    cout<<endl;

    return 0;
}
