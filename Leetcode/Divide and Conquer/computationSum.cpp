#include <iostream>
#include <bits/stdc++.h>

using namespace std;

// Solution class
class Solution {
    vector<int> currentStack;
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target, int pos=0) {
        
        vector<vector<int>> combination;
        
        if(target == 0 && currentStack.size() != 0) {
            vector<int> stackValue;
            for(auto ele : currentStack) {
                stackValue.push_back(ele);
            }
            combination.push_back(stackValue);
            return combination;
        }
        
        
        for(int i=pos; i<candidates.size(); i++) {
            if(target-candidates[i] >= 0) {
                currentStack.push_back(candidates[i]);
                vector<vector<int>> result = combinationSum(candidates, target-candidates[i], i);
                if(result.size() > 0) {
                    for(auto res : result) {
                        combination.push_back(res);
                    }
                }
                currentStack.pop_back();
            }
            pos++;
        }
        
        return combination;
        
    }
};

// Driver function
int main() {

    // Declaration of arguments
    vector<int> nums1 = {2,3,6,7};
    int target = 7;
    // Intialise and call of the function
    Solution sol;
    vector<vector<int>> result = sol.combinationSum(nums1, target);

    // Printing the result
    for(auto res : result) {
        cout<<endl;
        for(auto r : res) {
            cout<<r<<" ";
        }
        cout<<endl;
    }

    return 0;
}