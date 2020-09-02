#include <iostream>
#include <vector>

using namespace std;

vector<int> segmentTree(4*4, 0);

int CST(vector<int> &nums, int start, int end, int index) {
    // code for segment tree
    if(start == end) {
        segmentTree[index] = nums[start];
        return nums[start];
    }

    int mid = (start + end) / 2;
    segmentTree[index] = CST(nums, start, mid, 2*index+1) + CST(nums, mid+1, end, 2*index+2);
    return segmentTree[index];
}

void ConstructSegmentTree(vector<int> &nums) {
    CST(nums, 0, nums.size()-1, 0);
}

void Print(vector<int> &result) {
    for(auto r : result) {
        cout<<r<<" ";
    }
}

int main() {
    
    vector<int> nums = {10, 20, 30, 40};

    cout<<"Array to be made a segment Tree : ";
    Print(nums);
    ConstructSegmentTree(nums);
    cout<<"Segment Tree : "<<endl;
    Print(segmentTree);

    return 0;
}