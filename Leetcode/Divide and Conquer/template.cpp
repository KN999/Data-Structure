#include <iostream>
#include <bits/stdc++.h>

using namespace std;

// Solution class
class Solution {
public:
    // function to be implemented
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {

    }
};

// Driver function
int main() {

    // Declaration of arguments
    vector<int> nums1 = {1,3,5,7,9};
    vector<int> nums2 = {0,2,4,6,8};

    // Intialise and call of the function
    Solution sol;
    double result = sol.findMedianSortedArrays(nums1, nums2);

    // Printing the result
    cout<<result<<endl;

    return 0;
}