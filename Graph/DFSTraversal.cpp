#include "utils.h"
#include <iostream>
#include <vector>
#include <map>
#include <stack>
#include<set>
using namespace std;
vector<char> DFSIterative(map<char, vector<char>> graph, char position);
vector<char> DFS(map<char, vector<char>> graph, char position) {

    map<char, bool> visited;
    vector<char> result;
    stack<char> st;
    st.push(position);
    visited[position] = true;

    while(!st.empty()) {
        char current = st.top();
        st.pop();
        
        result.push_back(current);

        for(auto node : graph[current]) {
            if(visited[node] == false){
                st.push(node);
                visited[node] = true;
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
    vector<char> result = DFSIterative(graph, 'a');

    Print(result);
}

vector<char> DFSIterative(map<char, vector<char>> graph, char position) {

    stack<char> st;
    set<char> visited;
    vector<char> result;
    st.push(position);
    visited.insert(position);

    while(!st.empty()) {

        char ch = st.top();
        st.pop();

        result.push_back(ch);

        for(auto c : graph[ch]) {
            if(visited.find(c) == visited.end()) {
                visited.insert(c);
                st.push(c);
            }
        }
    }

    return result;

}