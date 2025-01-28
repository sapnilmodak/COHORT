#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
int mod = 1e9 + 7;
vector<vector<int>> g;
vector<int> visited;
vector<int> topo;
int dp[10010];
void dfs(int node){
    visited[node] = 1;
    for( auto v : g[node]){
        if(!visited[v]){
            dfs(v);
        }  
    }
    topo.push_back(node);
}
//to find the longest path from start node using dp
int rec(int node){
    if(dp[node] != -1) return dp[node];
    int ans =1;
    for(auto v:g[node]){
        ans = max(ans , 1+rec(v));
    }
    return dp[node] = ans;
}
void solution() {
    int n,m;
    cin>>n>>m;
    g.resize(n+1);
    topo.resize(n+1);
    dp.assign( n+1 , -1);
    for(int i=0; i<m; i++){
        int a,b;
        cin>>a>>b;
        g[a].push_back(b);
        //if its undirected
        g[b].push_back(a);
    }
    visited.assign(n+1 , 0);
    dfs(1);

    //this is topological ordering  
    // reverse(topo.begin() , topo.end());

    //if we want to find longest path of  topo vector
    int final =0;
    
    for(auto node : topo){
        int ans=1;
        for(auto v:g[node]){
            ans = max(ans , 1+dp[v]);
        }
        dp[node] = ans;
        final = max(final , dp[node]);
    }
    

}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solution();
    return 0;
}
