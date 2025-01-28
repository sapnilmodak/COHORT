#include <bits/stdc++.h>
using namespace std;

vector<int> bellman(int V, vector<vector<int>>& edges, int S) {
    vector<int> dist(V, 1e9);  // Use INT_MAX for clarity if desired
    dist[S] = 0;

    // Relax all edges V-1 times
    for (int i = 0; i < V - 1; i++) {
        for (auto& it : edges) {
            int u = it[0];
            int v = it[1];
            int wt = it[2];
            if (dist[u] != 1e9 && dist[u] + wt < dist[v]) {
                dist[v] = dist[u] + wt;
            }
        }
    }

    // Check for negative weight cycles
    for (auto& it : edges) {
        int u = it[0];
        int v = it[1];
        int wt = it[2];
        if (dist[u] != 1e9 && dist[u] + wt < dist[v]) {
            return {}; // Return empty vector if a negative cycle is detected
        }
    }

    return dist;
}

int main() {
    cout << "Enter number of vertices and edges:\n";
    int V, E;
    cin >> V >> E;

    vector<vector<int>> edges;

    cout << "Enter each edge in the format: u v wt\n";
    for (int i = 0; i < E; i++) {
        int u, v, wt;
        cin >> u >> v >> wt;
        edges.push_back({u, v, wt});
    }

    int S;
    cout << "Enter the source vertex:\n";
    cin >> S;

    vector<int> dist = bellman(V, edges, S);

    if (dist.empty()) {
        cout << "Graph contains a negative weight cycle.\n";
    } else {
        cout << "Shortest distances from source " << S << ":\n";
        for (int i = 0; i < V; i++) {
            if (dist[i] == 1e9) {
                cout << "INF ";
            } else {
                cout << dist[i] << " ";
            }
        }
        cout << '\n';
    }

    return 0;
}
