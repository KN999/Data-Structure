#include <iostream>
#include <bits/stdc++.h>

using namespace std;

// Solution class
class Solution {
    vector<int> currentStack;
    set<string> s;
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target, int pos=0) {
        
        vector<vector<int>> combination;
        
        if(target == 0 && currentStack.size() != 0) {
            vector<int> stackValue;
            string num = "";
            //sort(currentStack.begin(), currentStack.end());
            for(auto ele : currentStack) {
                stackValue.push_back(ele);
                num += ele;
            }
            sort(num.begin(), num.end());
            if(s.find(num) == s.end()) {
                s.insert(num);
                combination.push_back(stackValue);
            }
            //combination.push_back(stackValue);
            return combination;
        }
        
        
        for(int i=pos; i<candidates.size(); i++) {
            if(target-candidates[i] >= 0) {
                currentStack.push_back(candidates[i]);
                int sum = target -candidates[i];
                vector<vector<int>> result = combinationSum2(candidates, sum, i+1);
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
    vector<int> nums1 = {2,5,2,1,2};
    int target = 5;
    // Intialise and call of the function
    Solution sol;
    vector<vector<int>> result = sol.combinationSum2(nums1, target);

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