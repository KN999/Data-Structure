#include "utils.h"
#include <iostream>
#include <vector>
#include <map>
#include <set>
using namespace std;

vector<char> RecursiveDFSTraversal(map<char, vector<char>> graph, char position) {

    static vector<char> result;
    static set<char> visited;

    result.push_back(position);
    visited.insert(position);  // adding to the set

    for(auto node : graph[position]) {
        if(visited.find(node) == visited.end()) 
            RecursiveDFSTraversal(graph, node);
    }

    return result;
}

int main() {

    map<char, vector<char>> graph;
    graph.insert({'a', vector<char> ({'b', 'e'})});
    graph.insert({'b', vector<char> ({'c', 'd'})});
    graph.insert({'c', vector<char> ({'d'})});

    vector<char> result = RecursiveDFSTraversal(graph, 'a');

    Print(result);

    return 0;
}