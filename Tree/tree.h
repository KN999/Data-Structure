#include <vector>
#include <bits/stdc++.h> 
#include <queue>
using namespace std;

// class TrieNode {

//     public:
//         string word = "";
//         TrieNode * alphabet[26];

//         TrieNode():alphabet() {}
// };

// class Trie {
    
//     public :
//     TrieNode * root = nullptr;

//     Trie() {
//         root = nullptr;
//     }

//     void addword(string S) {
        
//         queue<TrieNode **> q;
//         q.push(&root);

//         for(auto s : S) {
            
            
//             TrieNode ** current = q.front();
//             q.pop();
//             int gate = (int)s % 97;

//             if(root == nullptr) {
//                 *current = new TrieNode();
//                 q.push(&(*current)->alphabet[gate]);
//             }
//             else {
//                 if((*current) == nullptr)
//                     (*current) = new TrieNode();

//                 q.push(&(*current)->alphabet[gate]);
//             }

//         }

//         TrieNode ** lastone = q.front();
//         q.pop();
//         *lastone = new TrieNode();
//         (*lastone)->word = S;
//     }
    
// };

class TrieNode {
public:   
    char c;
    bool isEnd;
    map<char, TrieNode*> children;

    TrieNode(char c) {
        this->c = c;
        this->isEnd = false;

        // for(char c='a'; c<='z'; c++)
        //     children[c] = nullptr;
    }

    void setIsEnd() {
        this->isEnd = true;
    }
};

class Trie {
public:
    TrieNode* root;

    Trie() {
        this->root = new TrieNode('*');
    }

    void addWord(string word) {
        TrieNode* current = root;

        for(auto c : word) {
            if(current->children.find(c) == (current->children).end()) {
                current->children[c] = new TrieNode(c);
            }
            current = current->children[c];
        }

        current->setIsEnd();
    }

    bool search(string word) {
        
        TrieNode * ite = root;

        for(auto c : word) {
            if(!ite->children[c])
                return false;
            ite = ite->children[c];
        }

        if(ite->isEnd)
            return true;

        return false;
    }
};


class TreeNode {

public:
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode (int value) {
        val = value;
        left = nullptr;
        right = nullptr;
    }
};

class Tree {

public:
    TreeNode* root;

    Tree () {
        root = nullptr;
    }

    Tree (vector<int> &nums) {

        root = nullptr;
        queue<TreeNode**> q;
        q.push(&root);

        for(auto num : nums) {

            if(num != -1) {
                TreeNode ** current = q.front();
                *current = new TreeNode(num);
                q.push(&((*current)->left));
                q.push(&((*current)->right));
            }

            q.pop();
           
        }
    }
};

/*
a 97
b 98
c 99
d 100
e 101
f 102
g 103
h 104
i 105
j 106
k 107
l 108
m 109
n 110
o 111
p 112
q 113
r 114
s 115
t 116
u 117
v 118
w 119
x 120
y 121
z 122
*/