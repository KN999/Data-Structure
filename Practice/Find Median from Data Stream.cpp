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
    priority_queue<int> max;
    priority_queue<int, vector<int>, greater<int>> min;
    
public:
    
    void addNum(int num) {
        max.push(num);
        min.push(max.top());
        max.pop();
        
        if(max.size() < min.size()) {
            max.push(min.top());
            min.pop();
        }
    }
    
    double findMedian() {
        int size = max.size() + min.size();
        
        if(size%2 == 0)
            return (max.top()+min.top())*0.5;
        else
            return max.top();
    }
};

int main()
{
    vector<int> nums({100, 4, 200, 1, 3, 2});

    Solution S;
    //int results = S.longestConsecutive(nums);
    
    //cout<<results<<endl;

    return 0;
}
