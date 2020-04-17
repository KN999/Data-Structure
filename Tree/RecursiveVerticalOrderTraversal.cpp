#include "tree.h"
#include "utils.h"
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void VerticalOrderUtil(TreeNode * root, map<int, vector<int>> &m, queue<pair<TreeNode *, int>> q) {

    if(!q.empty()) {
        auto current = q.front();
        q.pop();

        m[current.second].push_back((current.first)->val);
        
        if(current.first->left != NULL)
            q.push(make_pair(current.first->left, current.second - 1));
        if(current.first->right != NULL)
            q.push(make_pair(current.first->right, current.second + 1));

        VerticalOrderUtil(root, m, q);
    }

}

vector<vector<int>> RecursiveVerticalOrderTraversal(TreeNode * root) {

    map<int, vector<int>> m;
    queue<pair<TreeNode *, int>> q;
    q.push(make_pair(root, 0));
    vector<vector<int>> result;

    VerticalOrderUtil(root, m, q);

    for(auto hd : m) {
        vector<int> temp;
        for(auto Node : hd.second) {
            temp.push_back(Node);
        }
        result.push_back(temp);
    }

    return result;
}

int main () {

    vector<int> nums = {1,2,3,4,5,6,7};
    Tree tree(nums);

    auto result = RecursiveVerticalOrderTraversal(tree.root);

    Print(result);

    return 0; 
}