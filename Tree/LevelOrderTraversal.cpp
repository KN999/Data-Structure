#include "tree.h"
#include "utils.h"
#include <iostream>
using namespace std;

vector<vector<int>> LevelOrderTraversal (TreeNode * root) {

    queue<TreeNode *> q;
    vector<vector<int>> result;
    vector<int> level;

    q.push(root);
    q.push(nullptr);

    while(!q.empty()) {

        TreeNode * current = q.front();
        q.pop();

        if(current != nullptr) {
            level.push_back(current->val);

            if(current->left != NULL)
                q.push(current->left);
            
            if(current->right != NULL)
                q.push(current->right);

        }
        else {
             if(q.size() > 0)
                q.push(nullptr);

            result.push_back(level);
            level.clear();

        }

    }
    
    return result;
}

int main () {

    vector<int> nums = {1,2,3,NULL,NULL,6,7};
    Tree tree(nums);

    auto result = LevelOrderTraversal(tree.root);

    Print(result);

    return 0; 
}