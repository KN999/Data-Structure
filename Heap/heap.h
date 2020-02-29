#include <vector>
#include<math.h>
#include <queue>
//#include "utils.h"

using namespace std;
// Min Heap Tree Implementation
class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node(int val)
    {
        this->val = val;
        this->left = NULL;
        this->right = NULL;
    }
};

class MinHeapTree
{
    Node* root;
    queue<Node**> q;
    Node* lastNode;

    int swap(int &a, int &b)
    {
        int temp = a;
        a = b;
        b = temp;
    }  

    MinHeapTree() 
    {
        root = NULL;
        q.push(&root);
        lastNode = NULL;
    }

    void push(int num)
    {
        Node** currentNode = q.front();
        q.pop();
        *currentNode = new Node(num);
        lastNode = *currentNode;
        q.push(&((*currentNode)->left));
        q.push(&((*currentNode)->right));
    }

    // we have to check if the root value is greater then the newly inserted node.
    // If it is then need to move the value upwards. How to move upwards? Maybe having a pointer to parent! 
    // Think about in the morning or ask bhaiya. Also Minor project!!!
    
    void push(vector<int> nums)
    {
        for(auto num : nums)
            push(num);
    }

    int top()
    {
        if(root != NULL)
            return root->val;
        return -1;
    }

    void heapify(Node* root)
    {
        Node* smallest = root;

        if(root->left != NULL && smallest->val > root->left->val)
            smallest = root->left;
        if(root->right != NULL && smallest->val > root->right->val)
            smallest = root->right;

        if(smallest != root)
        {
            swap(smallest->val, root->val);
            heapify(smallest);
        }
    }

    void pop()
    {
        // how to update lastNode everytime deleting an element?
        if(root != lastNode)
        {
            swap(lastNode->val, root->val);
            delete(lastNode);
            heapify(root);
        }
        else 
        {
            delete(root);
            root = NULL;
        }
    }

};

// Min Heap Array Implementation
class MinHeapArray
{
    vector<int> heap;

public:
    int parent(int n) { return floor((n - 1) / 2); }
    int left(int n) { return 2 * n + 1; }
    int right(int n) { return 2 * n + 2;}
    int capacity() { return heap.size(); }

    int swap(int &a, int &b)
    {
        int temp = a;
        a = b;
        b = temp;
    }   

    void minheapify(int i) 
    {
        int smallest = i;
        int l = left(smallest);
        int r = right(smallest);

        if(l < capacity()-1 && heap[l] < heap[smallest])
            smallest = l;

        if(r < capacity()-1 && heap[r] < heap[smallest])
            smallest = r;

        if(i != smallest)
        {   
            swap(heap[i], heap[smallest]);
            minheapify(smallest);
        }
    }

    void push(int num)
    {
        heap.push_back(num);
        int node = heap.size()-1;

        while(heap[node] < heap[parent(node)])
        {
            swap(heap[node], heap[parent(node)]);
            node = parent(node);
        }
            
    }

    void push(vector<int> nums)
    {
        for(auto num : nums)       
            push(num);
    }

    int top()
    {
        if(capacity() == 0)
            return -1;
        else
            return heap[0];
    }

    void pop()
    {
        if (heap.size() == 0)
            return;
        if (heap.size() == 1)
            heap.erase(heap.begin()+0);

        swap(heap[0], heap[capacity() - 1]);
        heap.erase(heap.begin() + capacity() - 1);
        minheapify(0);
    }

    void print()
    {
        for(int i=0; i<capacity(); i++)
        {
            cout<<heap[i]<<" ";
        }
    }
};