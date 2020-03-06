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

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {};
    ListNode(int x) : val(x), next(nullptr) {};
    ListNode(int x, ListNode* next) : val(x), next(next) {};
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* result = nullptr;
        
        for(auto list : lists) {
            result = merge2Lists(result, list);
        }
        
        return result;
    }
    
    ListNode* merge2Lists(ListNode* l1, ListNode* l2) {
        if(l1 == nullptr)
            return l2;
        
        if(l2 == nullptr)
            return l1;
        
        ListNode* result = nullptr;
        ListNode* i = nullptr;
        
        while(l1 != nullptr && l2 != nullptr) {
            if(l1->val < l2->val) {
                if(result == nullptr) {
                    result = l1;
                    i = l1;
                    l1 = l1->next;
                }
                else {
                    i->next = l1;
                    l1 = l1->next;
                    i = i->next;
                }
            }
            else {
                if(result == nullptr) {
                    result = l2;
                    i = l2;
                    l2 = l2->next;
                }
                else {
                    i->next = l2;
                    l2 = l2->next;
                    i = i->next;
                }
            }
        }
        
        while(l1 != nullptr) {
            i->next = l1;
            l1 = l1->next;
            i = i->next;
        }
        
        while(l2 != nullptr) {
            i->next = l2;
            l2 = l2->next;
            i = i->next;
        }
        
        return result;
    }
};

int main()
{

    vector<ListNode*> lists;
    ListNode* l1 = new ListNode(1);
    l1->next = new ListNode(3);
    l1->next->next = new ListNode(5);

    ListNode* l2 = new ListNode(2);
    l2->next = new ListNode(4);
    l2->next->next = new ListNode(6);

    lists.push_back(l1);
    lists.push_back(l2);

    Solution S;
    ListNode* result = S.mergeKLists(lists);
    
    while(result != NULL) {
        cout<<result->val<<" ";
        result = result->next;
    }
    cout<<endl;

    return 0;
}
