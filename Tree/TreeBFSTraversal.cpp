#include "tree.h"
#include "utils.h"
#include <iostream>
using namespace std;

vector<int> TreeBFS(TreeNode * root) {

    queue<TreeNode **> q;
    vector<int> result;
    q.push(&root);

    while(!q.empty()) {
        TreeNode ** current = q.front();
        q.pop();

        result.push_back((*current)->val);

        if((*current)->left != NULL)
            q.push(&(*current)->left);
        
        if((*current)->right != NULL)
            q.push(&(*current)->right);
    }

    return result;
}

int main() {
    vector<int> nums = {1,2,3,4,5,6,7};

    Tree tree(nums);

    vector<int> result = TreeBFS(tree.root);

    Print(result);

    return 0;
}
