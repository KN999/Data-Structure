#include "utils.h"
#include<iostream>
#include<vector>
#include<map>
#include <queue>
using namespace std;

vector<char> BFS(map<char, vector<char>> graph, char position) {

    queue<char> q;
    map<char, bool> visited;
    vector<char> result;

    q.push(position);
    visited[position] = true;

    while(!q.empty()) {

        char ch = q.front();
        q.pop();
        result.push_back(ch);

        for(auto node : graph[ch]) {
            if(!visited[node]) {
                visited[node] = true;
                 q.push(node);
            }
        }
    }

    return result;
}

int main() {

    map<char, vector<char>> graph;
    vector<char> result;
    graph.insert({'a', vector<char> ({'b', 'c'})});
    graph.insert({'b', vector<char> ({'a', 'c'})});
    graph.insert({'c', vector<char> ({'b', 'd'})});
    graph.insert({'d', vector<char> ({'b', 'c'})});

    result = BFS(graph, 'a');

    Print(result);

}