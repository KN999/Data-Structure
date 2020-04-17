#include "tree.h"
#include "utils.h"
#include <iostream>
using namespace std;

vector<vector<int>> LevelOrderTraversal(TreeNode *root)
{

    queue<TreeNode *> q;
    vector<vector<int>> result;

    q.push(root);

    while (!q.empty())
    {

        int n = q.size();
        vector<int> level;

        while (n--)
        {
            TreeNode *current = q.front();
            q.pop();

            level.push_back(current->val);

            if (current->left != NULL)
                q.push(current->left);

            if (current->right != NULL)
                q.push(current->right);
        }

        result.push_back(level);
    }

    return result;
}

int main()
{

    vector<int> nums = {1, 2, 3, 4, 5, 6, 7};
    Tree tree(nums);

    auto result = LevelOrderTraversal(tree.root);

    Print(result);

    return 0;
}