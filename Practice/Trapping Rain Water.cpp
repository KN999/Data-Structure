#include<iostream>
#include<vector>
#include<map>
#include<bits/stdc++.h>
#include<algorithm>
#include<set>
#include<string.h>
#include<iomanip>
using namespace std;

class Solution {
public:
    int trap(vector<int>& heights) {
        int size = heights.size();

        if(size == 0)
            return 0;

        vector<int> leftMax(size);
        vector<int> rightMax(size);
        leftMax[0] = heights[0];
        rightMax[size-1] = heights[size-1];
        int rainWater = 0;

        for(int i=1; i<size; i++) {
            leftMax[i] = max(heights[i], leftMax[i-1]);
        }

        for(int i=size-2; i>=0; i--) {
            rightMax[i] = max(rightMax[i+1], heights[i]);
        }

        for(int i=0; i<size; i++) {
           rainWater += min(leftMax[i], rightMax[i]) - heights[i];
        }

        return rainWater;
    }
};

int main()
{
    vector<int> heights = {0,1,0,2,1,0,1,3,2,1,2,1};
    Solution S;
    int rainWater = S.trap(heights);

    cout<<rainWater;

    return 0;
}
