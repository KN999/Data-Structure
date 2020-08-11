#include "utils.h"
#include<iostream>
#include<vector>
#include<map>
#include <queue>
#include<set>
using namespace std;

vector<char> BFSIterative(map<char, vector<char>> graph, char position) {

    queue<char> q;
    set<char> visited;
    vector<char> result;
    q.push(position);
    visited.insert(position);

    while(!q.empty()) {
        char ch = q.front();
        q.pop();

        result.push_back(ch);

        for(auto c : graph[ch]) {
            if(visited.find(c) == visited.end()) {
                q.push(c);
                visited.insert(c);
            }
        }
    }

    return result;
}

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

map<char, vector<char>> getGraph (vector<vector<char>> connections) {

    map<char, vector<char>> graph;

    for(auto c : connections) {
        graph[c[0]].push_back(c[1]);
        graph[c[1]].push_back(c[0]);
    }

    return graph;
}

int main() {

    vector<vector<char>> connections({{'a', 'b'},{'a', 'c'}, {'b', 'c'}, {'c', 'd'}, {'d', 'b'}});
    map<char, vector<char>> graph = getGraph(connections);
    vector<char> result = BFSIterative(graph, 'a');

    Print(result);
}