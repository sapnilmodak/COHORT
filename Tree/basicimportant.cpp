#include <bits/stdc++.h>
using namespace std;
vector<int> g[10010];
int numchild[10010];
int dep[10010];
int par[10010];
bool isleaf[10010];
int subtreesumz[10010];
void dfs(int node , int parent , int depth){
    subtreesumz[node] =1;
    dep[node] = depth;
    par[node] = parent;
    numchild[node] =0;
    for(auto v: g[node]){
        if(v != parent){
            numchild[node]++;
            dfs(v , node , depth++);
            subtreesumz[node] += subtreesumz[v];
        }
    }
    if(numchild[node] == 0){
        isleaf[node] = 1;
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
    
}