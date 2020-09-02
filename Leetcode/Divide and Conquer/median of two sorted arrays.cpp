#include <iostream>
#include <bits/stdc++.h>

using namespace std;

// Solution class
class Solution {
public:
    // function to be implemented
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int size1 = nums1.size();
        int size2 = nums2.size();
        int low = 0;
        int high = size1-1;
        int Xpartition;
        int Ypartition;

        while(1) {
            Xpartition = (high - low)/2 + low;
            Ypartition = (size1 + size2 + 1)/2 - Xpartition;

            if(Xpartition-1 < 0)
                Xpartition = INT_MIN;
            else if(Xpartition >= size1)
                Xpartition = INT_MAX;

            if(Ypartition-1 < 0)
                Ypartition = INT_MIN;
            else if(Ypartition >= size1)
                Ypartition = INT_MAX;

            if((Xpartition != INT_MIN && Ypartition != INT_MAX) && nums1[Xpartition-1] > nums2[Ypartition])
                high = Xpartition-1;
            else if((Ypartition != INT_MIN && Xpartition != INT_MAX) && nums1[Xpartition] < nums2[Ypartition-1])
                low = Xpartition+1;
            else
                break;
            
        }

        if((size1 + size2) %2 == 0)
            return( (max(nums1[Xpartition-1], nums2[Ypartition-1]) + min(nums1[Xpartition], nums2[Ypartition])) / 2);
        else
            return max(nums1[Xpartition-1], nums2[Ypartition-1]);
    }
};

// Driver function
int main() {

    // Declaration of arguments
    vector<int> nums1 = {1,3};
    vector<int> nums2 = {2,4};

    // Intialise and call of the function
    Solution sol;
    double result = sol.findMedianSortedArrays(nums1, nums2);

    // Printing the result
    cout<<result<<endl;

    return 0;
}