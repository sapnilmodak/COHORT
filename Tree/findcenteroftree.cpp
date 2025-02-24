#include <bits/stdc++.h>
using namespace std;

vector<int> g[200010];
int dep[200010], par[200010];

void dfs(int node, int parent, int depth) {
    dep[node] = depth;
    par[node] = parent;
    for (auto v : g[node]) {
        if (v != parent) {
            dfs(v, node, depth + 1);
        }
    }
}

int getcenter(int length, int node) {
    if(length%2 == 1) return -1;
    
    int x = length / 2;

    while (x-- && node != 0) {  
        node = par[node];
    }
    return node;
}

int main() {
    int n;
    cin >> n;
    
    if (n == 1) {  
        cout << 1 << '\n';
    }

    for (int i = 1; i < n; i++) {  
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

  
    dfs(1, -1, 0);
    int maxchild = 1;
    for (int j = 2; j <= n; j++) {
        if (dep[maxchild] < dep[j]) {
            maxchild = j;
        }
    }

  
    dfs(maxchild, -1, 0);
    int maxchild1 = 1;
    for (int j = 2; j <= n; j++) {
        if (dep[maxchild1] < dep[j]) {
            maxchild1 = j;
        }
    }

    int center = getcenter(dep[maxchild1], maxchild1);

    cout  << center << '\n';

    return 0;
}
