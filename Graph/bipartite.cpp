#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
int mod = 1e9 + 7;
vector<vector<int>> g;
vector<int> visited;
bool is_bipartite = true;
void dfs(int node , int color){
    visited[node] = color;
    for(auto v : g[node]){
        if(!visited[v]){
            dfs(v , 3 - color);
        } 
        else if(visited[v] == visited[node]){
            is_bipartite= false;
        }
    }
}

void solution() {
    int n,m,q;
    cin>>n>>m>>q;
    g.resize(n+1);
    for(int i=0; i<m; i++){
        int a,b;
        cin>>a>>b;
        g[a].push_back(b);
        //if its undirected
        g[b].push_back(a);
    }
    int color =1;
    
    visited.assign(n+1 , 0);
    for(int i=1; i<=n; i++){
        if(!visited[i]){
            
            dfs(i , color);
        }
        
    }
    map<int ,int> freq;
    for(int i=1; i<=visited.size() ; i++){
       cout<<i<<" : "<<visited[i]<<'\n';
    }
   
   }

    


signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solution();
    return 0;
}
