#include<iostream>
#include<vector>
#include<map>
#include<bits/stdc++.h>
#include<algorithm>
#include<set>
#include<string.h>
#include<iomanip>
#include <stdio.h> 
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution
{
public:
    vector<string> tokenize(string str)
    {
        vector<string> tokens;
        string token = "";

        for(int i=0; i<str.size(); i++) {
            if(str[i] == ',' && token != "") {
                tokens.push_back(token);
                token = "";
            }
            else
                token += str[i];
        }

        return tokens;
    }

    string serialize(TreeNode *root)
    {
        string deserialiseString = "";
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()) {

            TreeNode* cur = q.front();
            q.pop();

            if(cur != NULL) {
                deserialiseString = (deserialiseString + to_string(cur->val));
                if(cur->left != NULL)
                    q.push(cur->left);
                else
                    q.push(NULL);
                
                if(cur->right != NULL)
                    q.push(cur->right);
                else
                    q.push(NULL);
            }
            else
                deserialiseString += "*";
            
            deserialiseString += ",";
        }

        return deserialiseString;
    }

    TreeNode* deserialize(string data)
    {
        vector<string> tokens = tokenize(data);
        
        if(tokens[0] == "*")
            return NULL;

        TreeNode* root = new TreeNode(stoi(tokens[0]));
        int i=1;
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()) {
            TreeNode* cur = q.front();
            q.pop();

            if(tokens[i] != "*") {
                cur->left = new TreeNode(stoi(tokens[i]));
                q.push(cur->left);
            }
            
            if(tokens[i+1] != "*") {
                cur->right = new TreeNode(stoi(tokens[i+1]));
                q.push(cur->right);
            }

            i += 2;
        }
        
        return root;
    }
};

void print(TreeNode* root) {
    if(root == NULL)
        return;

    cout<<root->val<<" ";
    
    if(root->left != NULL)
        print(root->left);
    
    if(root->right != NULL)
        print(root->right);
}

int main()
{
    // [1,2,3,null,null,4,5]
    TreeNode* root = NULL;

    Solution S;
    string strTree = S.serialize(root);
    cout<<strTree<<endl;
    TreeNode* result = S.deserialize(strTree);
    print(result);

    return 0;
}
