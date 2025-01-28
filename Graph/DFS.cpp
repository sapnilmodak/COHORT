#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
int mod = 1e9 + 7;
vector<vector<int>> g;
vector<int> visited;
void dfs(int node){
    visited[node] = 1;
    for( auto v : g[node]){
        if(!visited[v]){
            dfs(v);
        }  
    }
}
void solution() {
    int n,m;
    cin>>n>>m;
    g.resize(n+1);
    for(int i=0; i<m; i++){
        int a,b;
        cin>>a>>b;
        g[a].push_back(b);
        //if its undirected
        g[b].push_back(a);
    }
    visited.assign(n+1 , 0);
    dfs(1);
    
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solution();
    return 0;
}
