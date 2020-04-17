#include "tree.h"
#include "utils.h"
#include <iostream>
using namespace std;

vector<int> IterativePostOrderTraversal (TreeNode *root) {

    stack<TreeNode *> st;
    vector<int> result;
    TreeNode * previous = NULL;

    st.push(root);

    while(!st.empty()) {

        TreeNode * current = st.top();
        
        if(previous == NULL) {

            if(current->left != NULL)
                st.push(current->left);
            else if(current->right != NULL)
                st.push(current->right);
            else {
                st.pop();
                result.push_back(current->val);
                previous = current;
            }
        }
        else {

            if(previous == current->left && current->right != NULL) {

                st.push(current->right);
                previous = NULL;
            }
            else {

                st.pop();
                result.push_back(current->val);
                previous = current;
            }
        }
    }

    return result;
}


int main () {

    vector<int> nums = {1,2,3,4,5,6,7};
    Tree tree(nums);

    auto result = IterativePostOrderTraversal(tree.root);

    Print(result);

    return 0; 
}