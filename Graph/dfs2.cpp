#include <bits/stdc++.h>
using namespace std;


void printer(vector<int> x){
    cout<<"[ ";
    for(auto v:x){
        cout<<v<<", ";
    }
    cout<<"]\n";
}

int n,m;
vector<vector<int>> g;

vector<int> vis;
vector<int> comp_no;

void dfs(int x,int cc){
    vis[x]=1;
    comp_no[x]=cc;
    for(auto v:g[x]){
        if(!vis[v]){
            dfs(v,cc);
        }
    }
}

int main()
{
    cin>>n>>m;
    g.resize(n+1);
    vis.assign(n+1,0);
    comp_no.assign(n+1,0);
    for(int i=0;i<m;i++){
        int a,b;cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    int ans = 0;
    int cc = 0;
    for(int i=1;i<=n;i++){ 
        if(!vis[i]){
            cc++;
            dfs(i,cc);
        }
    }
    int q;
    cin>>q;
    while(q--){
        int a,b;
        cin>>a>>b;
        if(comp_no[a]==comp_no[b])cout<<"Yes\n";
        else cout<<"No\n";
    }
    
}