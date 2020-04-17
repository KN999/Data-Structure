#include "utils.h"
#include <iostream>
#include <vector>
#include <map>
#include <stack>

using namespace std;

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
            if(visited[current] == false){
                st.push(node);
                visited[current] = true;
            }
        }
    }

    return result;
}

int main() {

    map<char, vector<char>> graph;
    graph.insert({'a', vector<char> ({'b', 'c'})});
    graph.insert({'b', vector<char> ({'a', 'c'})});
    graph.insert({'c', vector<char> ({'b', 'd'})});
    graph.insert({'d', vector<char> ({'b', 'c'})});

    vector<char> result = DFS(graph, 'a');

    Print(result);

}