#include "tree.h"
#include <iostream>
#include <string>
using namespace std;

int main() {

  // TrieNode * root = new TrieNode();
  // root->alphabet[1] =  new TrieNode();
 
  Trie trie;
  trie.addWord("abc");
  trie.addWord("abd");
  
  return 0;
}

// int main () {


// TreeNode * root = new TreeNode(1);
// root->left = new TreeNode(2);
// root->right = new TreeNode(3);
// root->left->left = new TreeNode(4);
// root->left->right = new TreeNode(5);
// root->right->left = new TreeNode(6);
// root->right->right = new TreeNode(7);

// BottomView_Traversal(root);

//     /* ---------Tree---------
//     vector<int> nums = {1,2,3};
//     Tree root(nums);
//     */
   
//     return 0; 
// }
