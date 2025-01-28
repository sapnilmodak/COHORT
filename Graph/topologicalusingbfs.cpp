#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
int mod = 1e9 + 7;
vector<vector<int>> g;
vector<int> indegree;
vector<int> topo;
int n;
void kahn(){
    priority_queue<int> q;
    for(int i=1; i<=n; i++){
        if(indegree[i] == 0){
            q.push(-i);
        }
    }
    while(!q.empty()){
        int curr = -q.top();
        topo.push_back(curr);
        q.pop();
        for(auto v:g[curr]){
            indegree[v]--;
            if(indegree[v] == 0){
                q.push(-v);
            }
        }
    }
}
void solution() {
    int m;
    cin>>n>>m;
    g.resize(n+1);
    topo.resize(n+1);
    indegree.resize(n+1);
    for(int i=0; i<m; i++){
        int a,b;
        cin>>a>>b;
        g[a].push_back(b);
        //if its undirected
        indegree[b]++;
    }
    kahn();
    for(auto v:topo){
        cout<<v<<" ";
    }

}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solution();
    return 0;
}
