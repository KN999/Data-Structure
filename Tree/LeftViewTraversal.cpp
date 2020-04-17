#include "tree.h"
#include "utils.h"
#include <iostream>
using namespace std;

vector<int> LeftViewTraversal (TreeNode * root) {

    queue<TreeNode *> q1;
    queue<TreeNode *> q2;
    vector<int> result;

    q1.push(root);

    while(1) {
        if(!q1.empty() && q2.empty()) {

            TreeNode * cur = q1.front();

            result.push_back(cur->val);

            while(!q1.empty()) {
                TreeNode * current = q1.front();
                q1.pop();

                if(current->left != NULL)
                    q2.push(current->left);
                
                if(current->right != NULL)
                    q2.push(current->right);
            }
        }
        else if(!q2.empty() && q1.empty()) {

            TreeNode * cur = q2.front();

            result.push_back(cur->val);

            while(!q2.empty()) {

                TreeNode * current = q2.front();
                q2.pop();

                if(current->left != NULL)
                    q1.push(current->left);
                
                if(current->right != NULL)
                    q1.push(current->right);
            }
        }
        else
            break;
    }

    return result;
}

int main () {

    vector<int> nums = {1,2,3,4,5,6,7};
    Tree tree(nums);

    auto result = LeftViewTraversal(tree.root);

    Print(result);

    return 0; 
}