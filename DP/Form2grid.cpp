/*
find total number of path to reach nth row and mth column in a grid, where you can only move down or right.
You can also add obstacles in the grid, which will block the path.
*/
#include <bits/stdc++.h>
using namespace std;
vector<vector<int>>grid;
int n,m;
int dp[1001][1001];

int rec(int i,int j){
    //prune
    if(grid[i][j] == '#') return 0;
    //base
    if(i==0 && j==0 ) return 1;
    
    int ans =0;
    //cache
    if(dp[i][j] != -1){
        return dp[i][j];
    }
    //transaction
    if(i-1 >=0 ){
        ans += dp[i-1][j];
    }
    if(j-1 >= 0){
        ans += dp[i][j-1];
    }
    //return
    return dp[i][j] =ans;
}

int main(){
    cin>>n>>m;
    grid.resize(n);
    for(int i=0; i<n; i++){
        grid[i].resize(m);
        for(int j=0; j<m; j++){
            cin>>grid[i][j];
        }
    }
    memset(dp , -1, sizeof(dp));
    cout<<rec(n,m)<<'\n';
}