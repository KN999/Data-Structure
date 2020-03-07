#include<iostream>
#include<vector>
#include<map>
#include<bits/stdc++.h>
#include<algorithm>
#include<set>
#include<string.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(NULL) {}
    ListNode(int x) : val(x), next(NULL) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* solve(ListNode* l1, ListNode* l2) {
        ListNode* result = NULL;
        ListNode* ite = NULL;

        while (l1 != NULL && l2 != NULL)
        {
            if (l1->val < l2->val)
            {
                if (result == NULL)
                {
                    result = l1;
                    ite = result;
                    l1 = l1->next;
                }
                else
                {
                    ite->next = l1;
                    l1 = l1->next;
                    ite = ite->next;
                }
            }
            else
            {
                if (result == NULL)
                {
                    result = l2;
                    ite = result;
                    l2 = l2->next;
                }
                else
                {
                    ite->next = l2;
                    l2 = l2->next;
                    ite = ite->next;
                }
            }
        }

        while (l1 != NULL)
        {
            if (result == NULL)
            {
                result = l1;
                ite = result;
                l1 = l1->next;
            }
            else
            {
                ite->next = l1;
                l1 = l1->next;
                ite = ite->next;
            }
        }

        while (l2 != NULL)
        {
            if (result == NULL)
            {
                result = l2;
                ite = result;
                l2 = l2->next;
            }
            else
            {
                ite->next = l2;
                l2 = l2->next;
                ite = ite->next;
            }
        }

        return result;
    }
};

int main()
{

    ListNode *l1 = new ListNode(1);
    l1->next = new ListNode(2);
    l1->next->next = new ListNode(4);

    ListNode *l2 = new ListNode(1);
    l2->next = new ListNode(3);
    l2->next->next = new ListNode(4);

    Solution S;
    ListNode *result = S.solve(l1, l2);

    while(result != NULL) {
        cout<<result->val<<" ";
        result = result->next;
    }

    cout<<endl;

    return 0;
}
