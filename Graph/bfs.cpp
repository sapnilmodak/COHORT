#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
int mod = 1e9 + 7;
vector<vector<int>> g;
vector<int> visited;
vector<int> dis;
std::queue<int>q;
void bfs(int sc_node){
    visited[sc_node] =1;
    dis[sc_node] = 0;
    q.push(sc_node);
    while(!q.empty()){
        int node = q.front();
        q.pop();
        for(auto v:g[node]){
            if(!visited[v]){
                visited[v]=1;
                q.push(v);
                dis[v]= dis[node]+1;
            }
            
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
    dis.assign(n+1 , 1e9);
    for(int i=1; i<=n; i++){
        cout<<i<<" : "<<visited[i]<<" , "<<dis[i]<<'\n';
    }
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solution();
    return 0;
}
 