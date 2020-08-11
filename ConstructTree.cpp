#include"tree.h"
#include"utils.h"
#include <iostream>
#include <vector>
#include <map>
using namespace std;

map<int, int> m;
int psize;

TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
    
    for(int i=0; i<inorder.size(); i++)
        m[inorder[i]] = i;
    
    psize = postorder.size()-1;
    
    return Tree(postorder, 0, psize);
}

TreeNode* Tree(vector<int>& postorder, int left, int right) {
    
    TreeNode* root = NULL;
    
    if(left <= right) {
        int indexval = postorder[psize];
        root = new TreeNode(indexval);
        root->right = Tree(postorder, m[indexval]+1, right);
        root->left = Tree(postorder, left, m[indexval]-1);
        psize--;
        
    }
    
    return root;
}

int main() {

    vector<int> inorder = {9,3,15,20,7};
    vector<int> postorder = {9,15,7,20,3};

    buildTree(inorder, postorder);

    return 0;
}
