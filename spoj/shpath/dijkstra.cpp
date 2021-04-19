#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <assert.h>
#include <math.h>
#include <tuple>
#include <unordered_map>
#include <set>

using namespace std;

typedef pair<int, int> pair_i;

struct Edge {
    int to;
    int cost;
};

int findMinCost(vector<vector<Edge>> &graph, int source, int target) {
    if(source == target) return 0;

    int n = graph.size();

    vector<int> minDist(n);
    for(int i=1;i<n;i++) 
        minDist[i] = INT_MAX;
    minDist[source] = 0;

    set<pair_i> set;
    set.insert({0, source});

    while(!set.empty()) {
        auto node = set.begin();
        int node_id = node->second;

        if(target == node_id) {
            return node->first;
        }

        for(auto ed : graph[node_id]) {
            int new_cost = ed.cost+minDist[node_id];

            if(new_cost < minDist[ed.to]) {              

                set.erase({minDist[ed.to], ed.to});
                minDist[ed.to] = new_cost;
                set.insert({minDist[ed.to], ed.to});
            }
        }

        set.erase(node);
    }

    return INT_MAX;
}

int main() {
    int S, n, p, r;
    string city, source, target;
    cin >> S;

    for(int s=0;s<S;s++) {
        cin >> n;
        unordered_map<string, int> map;
        vector<vector<Edge>> graph(n);

        for(int i=0;i<n;i++) {
            cin >> city >> p;
            map[city] = i;
            graph[i] = vector<Edge>(p);

            for(int j=0;j<p;j++) {
                int to, cost;
                cin >> to >> cost;
                Edge edge;
                edge.cost = cost;
                edge.to = to-1;
                graph[i][j]= edge;
            }
        }

        cin >> r;

        for(int j=0;j<r;j++) {
            cin >> source >> target;
            cout << findMinCost(graph, map[source], map[target]) << "\n";
        }
        
    }
}