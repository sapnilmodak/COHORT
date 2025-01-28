#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> g;
vector<int> color;
vector<int> parents;
bool is_cycle = 0;
vector<int> cycle;
vector<int> cntcycle;
vector<int> prefixorder;
void dfs(int node , int par){
    color[node]=2;
    parents[node] = par;
    for(auto v:g[node]){
        //this if only in undirectd case 
        if(v == parents[node]) continue;
        if(color[v] == 1){
            //forward
            dfs( v , node);
        }
        else if(color[v] == 2){
            //backward
            if(is_cycle == 0){
                int temp = node;
                while(temp!=v){
                    cycle.push_back(temp);
                    temp = parents[temp];
                }
                cycle.push_back(temp);
            }
            cntcycle[node]++;
            cntcycle[parents[v]]--;
            is_cycle =1;
        }
        else if(color[v] == 3){
            //continue
        }
    }
    color[node] =3;
    prefixorder.push_back(node);
}
int main(){
    int n,m;
    cin>>n>>m;
    g.resize(n+1);
    for(int i=0; i<m; i++){
        int a,b;
        cin>>a>>b;
        g[a].push_back(b);
        //undirectd
        g[b].push_back(a);
    }
    color.assign( n+1 , 1 );
    parents.resize(n+1 );
    // cycle.resize(n+1);
    cntcycle.assign( n ,0);
    reverse(cycle.begin() , cycle.end());
    for(int i=1; i<=n; i++){
        if(color[i] ==1){
            dfs(i , 0);
        }
    }
    for(auto it:cycle){
        cout<<it<<" ";
    }
    cout<<'\n';
    for(auto v:prefixorder){
        cntcycle[parents[v]] += cntcycle[v];
    }
    //counting the number of node which are present in cycle 
    int cnt=0;
    for(auto it:cntcycle){
        if(it>0){
            cnt++;
        }
    }
    cout<<cnt<<'\n';
}