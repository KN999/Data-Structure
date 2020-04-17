#include "tree.h"
#include "utils.h"
#include <iostream>
using namespace std;

vector<vector<int>> ZigZagTraversal (TreeNode * root) {

    stack <TreeNode *> st1;
    stack <TreeNode *> st2;
    vector<vector<int>> result;

    st1.push(root);

    while(1) {

        vector<int> level;

        if(st1.empty() && !st2.empty()) {
            // Do Something
           while(!st2.empty()) {
                TreeNode * current = st2.top();
                st2.pop();

                level.push_back(current->val);
                
                if(current->right != NULL)
                    st1.push(current->right) ;

                if(current->left != NULL)
                    st1.push(current->left);
           }

        }
        else if(!st1.empty() && st2.empty()) {
            // Do Something
            while(!st1.empty()) {

                TreeNode * current = st1.top();
                st1.pop();

                level.push_back(current->val);

                if(current->left != NULL)
                    st2.push(current->left);
                
                if(current->right != NULL)
                    st2.push(current->right);
            }

        }
        else
            break;

        result.push_back(level);
    }

    return result;
}

int main () {

    vector<int> nums = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15};
    Tree tree(nums);

    auto result = ZigZagTraversal(tree.root);

    Print(result);

    return 0; 
}