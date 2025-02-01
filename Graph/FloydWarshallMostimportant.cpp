#include <bits/stdc++.h>
using namespace std;
int n,m;
int dist[404][404];
int par[404][404];
void printpath(int i,int j){
    if(i!=j) printpath(i , par[i][j]);
    
    cout<<j<<" ";
}
int main(){
    // it can be use when nodes <= 400
    cin>>n>>m;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(i!=j) dist[i][j] =1e9;
        }
    }
    for(int k=0; k<m; k++){
        int a,b,c;
        cin>>a>>b>>c;
        dist[a][b] = min(dist[a][b] , c);
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            par[i][j] =i;
        }
    }
    //dist[i][j] -> means shortest distance between node i and j
    for(int k=0; k<n; k++){
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(dist[i][j] > dist[i][k] + dist[k][j]){
                    dist[i][j] = dist[i][k] + dist[k][j];
                    par[i][j] = par[k][j];
                }
            }
        }
    }
    
    /*2) transitive closure to find which all are reacahable */
    for(int k=0; k<m; k++){
        int a,b,c;
        cin>>a>>b>>c;
        dist[a][b] = 1;
    }
    for(int k=0; k<n; k++){
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                dist[i][j] = dist[i][j] | (dist[i][k] & dist[k][j]);
            }
        }
    }
    // 3) find the shortest cycle
    
     for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            dist[i][j] =1e9;
        }
    }
    for(int k=0; k<m; k++){
        int a,b,c;
        cin>>a>>b>>c;
        dist[a][b] = min(dist[a][b] , c);
    }
    for(int k=0; k<n; k++){
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                dist[i][j] = min(dist[i][j] , dist[k][j] + dist[i][k]);
            }
        }
    }
    int ans =0;
    for(int i=0; i<n; i++){
        ans = min(ans , dist[i][i]);
    }
    cout<<ans<<'\n';
    
    // find negative cycle in this 
    if(ans < 0){
        cout<<"YES";
    }
    else{
        cout<<"NO";
    }
    //diatmeter -> longest shortest path we can find easily as we have all pair shortest path 
}