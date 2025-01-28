#include <bits/stdc++.h>
using namespace std;
int n,m;
vector<pair<int,int>> g;
int dis[1001];
void bfs0_1(int st_node){
    for(int i=1; i<=n; i++){
        dis[i] = 1e9;
    }
    dis[st_node] =0;
    deque<int> dq;
    dq.push_back(st_node);
    while(!dq.empty()){
        int curr = dq.front();
        dq.pop_back();
        for(auto v:g[curr]){
            int neigh = v.first;
            int weight = v.second;
            if(dis[neigh] > dis[curr]+weight){
                dis[neigh] = dis[curr]+weight;
                if(weight == 0){
                    dq.push_front(neigh);
                }
                else{
                    dq.push_back(neigh);
                }
            }
        }
    }
}
int main(){
    cin>>n>>m;
    g.resize(n+1);
    for(int i=0; i<m; i++){
        int a,b,c;
        cin>>a>>b>>c;
        g[a].push_back({b,c});
        g[b].push_back({a,c});
    }
    int st;
    cin>>st;
    bfs0_1(st);
    for(int i=1; i<=n; i++){
        cout<<dis[i]<<" ";
    }
}