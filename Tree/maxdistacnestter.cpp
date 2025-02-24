/* for every node find max(abs( val[x] - val[y] )) where x is current node and y is any  ancesster */
#include <bits/stdc++.h>
using namespace std;
int val[10010];
int ans[10010];
vector<int> g[10010];
void dfs(int node , int par , int maxval , int minval){
    ans[node] = max(abs(maxval - val[node]) , abs(minval - val[node]));
    for(auto v:g[node]){
        if(v != par){
            dfs(v , node , max(val[node] , maxval) , min(val[node] , minval));
        }
    }
}
int main(){
    int n;
    cin>>n;
    for(int i=1; i<=n-1; i++){
        int a,b;
        cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    for(int i=1; i<=n; i++){
        int x;
        cin>>x;
        val[i]  = x;
    }
    int root;
    cin>>root;
    dfs(root , 0 , -1e9 , 1e9);
    for(auto it:ans){
        cout<<it<<" ";
    }
}
