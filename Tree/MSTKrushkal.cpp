#include <bits/stdc++.h>
using namespace std;
#define int long long
int n;
int par[200100], ranked[200100];
int set_size;

void unionfind() {  
    set_size = n;
    for (int i = 1; i <= n; i++) par[i] = i;
    for (int i = 1; i <= n; i++) ranked[i] = 1;
}

int find(int x) {
    if (par[x] == x) return x;
    return par[x] = find(par[x]);  
}

void merge(int x, int y) {
    int x_root = find(x);
    int y_root = find(y);
    if (x_root != y_root) {
        if (ranked[x_root] > ranked[y_root]) {
            ranked[x_root] += ranked[y_root];
            par[y_root] = x_root;
        } else {
            ranked[y_root] += ranked[x_root];
            par[x_root] = y_root;
        }
        set_size--;
    }
}

signed  main() {
    int m;
    cin >> n >> m;
    unionfind();
    
    vector<pair<int, pair<int, int>>> edge_list;  
    
    for (int i = 1; i <= m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        edge_list.push_back({c, {a, b}});
    }
    
    sort(edge_list.begin(), edge_list.end()); 
    int mst = 0, cnt = 0;
    
    for (auto it : edge_list) {
        int x = it.second.first;
        int y = it.second.second;
        
        if (find(x) != find(y)) {  
            merge(x, y);
            mst += it.first;
            cnt++;
        }
    }
    
    if (cnt != n - 1) {  
        cout << -1 << '\n';
        return 0;
    }
    
    cout << mst << '\n';
    return 0;
}
