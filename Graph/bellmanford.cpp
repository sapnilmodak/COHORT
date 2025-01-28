#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<vector<pair<int, int>>> g;
vector<int> dis;

bool bellmanFord(int node) {
    dis[node] = 0; // Initialize the source node distance to 0

    // Relax all edges (n-1) times
    for (int k = 1; k < n; k++) {
        for (int u = 1; u <= n; u++) {
            for (auto& edge : g[u]) {
                int v = edge.first;
                int wt = edge.second;
                if (dis[u] != -1e9 && dis[v] < dis[u] + wt) {
                    dis[v] = dis[u] + wt; // Relax the edge
                }
            }
        }
    }

    // Check for positive-weight cycles
    for (int u = 1; u <= n; u++) {
        for (auto& edge : g[u]) {
            int v = edge.first;
            int wt = edge.second;
            if (dis[u] != -1e9 && dis[v] < dis[u] + wt) {
                return true; // Positive-weight cycle detected
            }
        }
    }

    return false; // No positive-weight cycle
}

int main() {
    cin >> n >> m;
    g.resize(n + 1);
    dis.assign(n + 1, -1e9); // Initialize distances to -infinity

    // Read the graph
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        g[a].push_back({b, c}); // Directed edge from a to b with weight c
    }

    // Run Bellman-Ford from node 1
    bool hasPositiveCycle = bellmanFord(1);

    if (hasPositiveCycle) {
        cout << -1 << '\n'; // Print -1 if a positive-weight cycle is detected
    } else {
        cout << dis[n] << '\n'; // Print the highest weighted path from 1 to n
    }

    return 0;
}