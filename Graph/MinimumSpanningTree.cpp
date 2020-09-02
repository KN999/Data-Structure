#include "utils.h"
#include<iostream>
#include<vector>
#include<map>
#include <queue>
#include<set>
using namespace std;

int MST(vector<vector<int>> graph, int position) {
    set<int> visited = {position};
    set<int> unvisited = {};

    for(int i=1; i<graph.size(); i++)
        unvisited.insert(i);

    int cost = 0;

    while(!unvisited.empty()) {
        int Min = INT_MAX;
        int u = -1;
        for(auto i=visited.begin(); i!=visited.end(); i++) {
            for(auto j=unvisited.begin(); j!=unvisited.end(); j++) {
                if(graph[*i][*j] != 0 && graph[*i][*j] < Min) {
                    u = *j;
                    Min = graph[*i][*j];
                }
            }
        }
        cost += Min;
        visited.insert(u);
        unvisited.erase(u);
    }

    return cost;
}


int main() {

    vector<vector<int>> graph({
        {0, 5, 8, 0},
        {5, 0, 10, 15},
        {8, 10, 0, 20},
        {0, 15, 20, 0}
    });

    int result = MST(graph, 0);

    cout<<result<<"\n";
}