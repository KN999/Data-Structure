#include "tree.h"
#include "utils.h"
#include <iostream>
using namespace std;

vector<int> IterativeInorderTraversal (TreeNode * root) {

    stack <TreeNode *> st;
    unordered_map <TreeNode*, bool> umap;
    vector<int> result;

    st.push(root);

    while(!st.empty()) {

        TreeNode * current = st.top();
        st.pop();

        if(umap.find(current) != umap.end()) {
            result.push_back(current->val);
        }
        else {
            if(current->right != NULL)
                st.push(current->right);

            st.push(current);
            umap[current] = true;

            if(current->left != NULL)
                st.push(current->left);
        }
    }

    return result;
}

int main () {

    vector<int> nums = {1,2,3,4,5,6,7};
    Tree tree(nums);

    auto result = IterativeInorderTraversal(tree.root);

    Print(result);

    return 0; 
}