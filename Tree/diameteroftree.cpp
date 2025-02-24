#include <bits/stdc++.h>
using namespace std;
vector<int> g[200010];
int numchild[200010];
int dep[200010];
int par[200010];

void dfs(int node , int parent , int depth){
    dep[node] = depth;
    par[node] = parent;
    for(auto v: g[node]){
        if(v != parent){
            dfs(v , node , depth+1);
        }
    }
}
int main(){
    int n;
    cin>>n;
    for(int i=0; i<n; i++){
        int a,b;
        cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    dfs(1 , 0 , 0);
    int maxchild =1;
    for(int j=2; j<=n; j++){
        if(dep[maxchild] < dep[j]){
            maxchild = j;
        }
    }
    dfs(maxchild  , 0 , 0);
    int maxchild =1;
    for(int j=2; j<=n; j++){
        if(dep[maxchild] < dep[j]){
            maxchild = j;
        }
    }
    cout<<dep[maxchild]<<'\n';
}