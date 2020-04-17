#include "tree.h"
#include "utils.h"
#include <iostream>
using namespace std;

vector<int> RightViewTraversal( TreeNode * root ) {

    queue<TreeNode *> q1;
    queue<TreeNode *> q2;
    vector<int> result;
    
    q1.push(root);

    while(1) {

        if(!q1.empty() && q2.empty()) {
            
            while(!q1.empty()) {

                TreeNode * current = q1.front();
                q1.pop();

                if(q1.empty())
                    result.push_back(current->val);

                if(current->left != NULL)
                    q2.push(current->left);

                if(current->right != NULL)
                    q2.push(current->right);
            }
        }
        else if(!q2.empty() && q1.empty()) {

            while(!q2.empty()) {

                TreeNode * current = q2.front();
                q2.pop();

                if(q2.empty())
                     result.push_back(current->val);

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

    auto result = RightViewTraversal(tree.root);

    Print(result);

    return 0; 
}