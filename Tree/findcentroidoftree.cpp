#include <bits/stdc++.h>
using namespace std;

const int N = 10010;
vector<int> g[N];
int subtree[N], n;

void dfs(int node, int par) {
    subtree[node] = 1;
    for (auto v : g[node]) {
        if (v != par) {
            dfs(v, node);
            subtree[node] += subtree[v];
        }
    }
}

int find_centroid(int node, int par) {
    for (auto v : g[node]) {
        if (v != par && subtree[v] > (n / 2)) {
            return find_centroid(v, node);
        }
    }
    
    if(n - subtree[node] > n/2) {
        return -1; 
    }
    return node;
}

int main() {
    cin >> n;
    for (int i = 1; i < n; i++) {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);  
    }
    
    dfs(1, -1);
    int centroid = find_centroid(1, -1);
    if(centroid != -1) {
        cout << centroid << '\n';
    } else {
        cout << "No centroid found" << '\n';
    }
    
    return 0;
}
