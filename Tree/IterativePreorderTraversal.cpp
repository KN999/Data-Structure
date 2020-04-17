#include "tree.h"
#include "utils.h"
#include <iostream>
using namespace std;

vector<int> IterativePreOrderTraversal (TreeNode * root) {

    stack<TreeNode *>st;
    vector<int> result;
    st.push(root);

    while(!st.empty()) {

        TreeNode * current = st.top();
        st.pop();
        
        result.push_back(current->val);
        
        if(current->right != NULL)
            st.push(current->right);

        if(current->left != NULL)
            st.push(current->left);
    }

    return result;
}

int main () {

    vector<int> nums = {15, 26, 38,45, 32, 76, 43};
    Tree tree(nums);

    auto result = IterativePreOrderTraversal(tree.root);

    Print(result);

    return 0; 
}