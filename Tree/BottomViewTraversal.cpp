#include "tree.h"
#include "utils.h"
#include <iostream>
using namespace std;

vector<int> BottomViewTraversal(TreeNode * root) {

    queue<TreeNode *> q;
    vector<int> result;

    q.push(root);

    while(!q.empty()) {

        TreeNode * current = q.front();
        q.pop();

        if(current->left != NULL)
            q.push(current->left);
        
        if(current->right != NULL)
            q.push(current->right);

        if(current->left == NULL && current->right == NULL)
            result.push_back(current->val);
    }

    return result;
}

int main () {

    vector<int> nums = {1,2,3,4,-1,-1,7,-1,9};
    Tree tree(nums);

    auto result = BottomViewTraversal(tree.root);

    Print(result);

    return 0; 
}