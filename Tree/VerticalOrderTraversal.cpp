#include "tree.h"
#include "utils.h"
#include <iostream>
using namespace std;

vector<vector<int>> VerticalOrderTraversal(TreeNode * root) {

    vector<vector<int>> result;
    queue <pair<TreeNode *, int>> q;
    map <int, vector<int>> m;

    q.push(make_pair(root, 0));

    while(!q.empty()) {

        pair<TreeNode *, int> current;
        current = q.front();
        q.pop();

        int hd = current.second;
        TreeNode * temp =  current.first;

        m[hd].push_back(temp->val);

        if(temp->left != NULL)
            q.push(make_pair(temp->left, hd-1));
        
        if(temp->right != NULL)
            q.push(make_pair(temp->right, hd+1));

    }

    for(auto level : m) {
        result.push_back(level.second);
    }

    return result;
}

int main () {

    vector<int> nums = {1,2,3,4,-1,-1,5};
    Tree tree(nums);

    auto result = VerticalOrderTraversal(tree.root);

    Print(result);

    return 0; 
}