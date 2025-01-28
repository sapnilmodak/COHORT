#include <bits/stdc++.h>
using namespace std;
using ii = pair<int, int>; // Pair to represent {distance, node}
using ll = long long;
vector<vector<ii>> g;
ll dis[10010];
ll n,m;
// the priority_queue has first distance and second node number to get sorted
// but graph has first node and second distance
void djkestra(int node){
    dis[node]=0;
    priority_queue<ii> pq;
    pq.push({-0 , node});
    while(!pq.empty()){
        ii curr = pq.top();
        pq.pop();
        for(auto v:g[curr.second]){
            int neigh = v.first;
            int wt = v.second;
            if(dis[neigh] > dis[curr.second] + wt){
                dis[neigh] = dis[curr.second] + wt;
                pq.push({-wt , neigh});
            }
        }
    }
}

int main(){
    cin>>n>>m;
    for(int i=0; i<m; i++){
        // a and b are node and c is distance betwen them
        int a,b,c;
        g[a].push_back({b,c});
        g[b].push_back({a , c});
    }
    djkestra(1);
}