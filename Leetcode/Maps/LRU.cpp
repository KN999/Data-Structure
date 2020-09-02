#include <iostream>
#include <vector>
#include <map>
#include <bits/stdc++.h>

using namespace std;

class Node {
public:
    int val;
    int key;
    Node* next;
    Node* previous;
    
    Node(int val, int key) {
        this->val = val;
        this->key = key;
        this->next = nullptr;
        this->previous = nullptr;
    }
};

class LRUCache {
    int capacity;
    Node* head;
    Node* tail;
    map<int, Node*> m;
    
public:
    LRUCache(int capacity) {
        this->capacity = capacity;
        head = nullptr;
        tail = nullptr;
    }
    
    int get(int key) {
        if(m.find(key) != m.end()) {
            // change the position in linkedlist
            Node* ptr = m[key];
            if(ptr->previous == NULL) {
                tail = ptr->next;   
            }
            else {
                Node* pre = ptr->previous;
                pre->next = ptr->next;
            }
            
            
            head->next = ptr;
            ptr->previous = head;
            ptr->next = NULL;
            
            return m[key]->val;
        }
        
        return -1;
    }
    
    void put(int key, int value) {
        if(m.find(key) == m.end()) {
            if(m.size() != capacity) {
                if(head == nullptr) {
                    head = new Node(value, key);
                    tail = head;
                }
                else {
                    Node* ptr = new Node(value, key);
                    head->next = ptr;
                    ptr->previous = head;
                    head = head->next;
                }
                
                m[key] = head;
            }
            else {
                Node* ptr1 = tail;
                tail = tail->next;
                m.erase(ptr1->key);
                delete ptr1;
                
                Node* ptr = new Node(value, key);
                head->next = ptr;
                ptr->previous = head;
                head = head->next;
                m[key] = head;
            }
        }
    }
};


int main() {
    LRUCache* obj = new LRUCache(1);
    obj->put(1,1);
    obj->put(2,2);
    int param_1 = obj->get(3);
    obj->put(3,3);
    int param_2 = obj->get(2);
    obj->put(4,4);
    int param_3 = obj->get(1);
}