#include<bits/stdc++.h>
using namespace std;
vector<int> arr;
int dp[1001];
int rec(int level){
    //basecase
    if(dp[level] != -1) return dp[level];
    //transaction
    int ans=-1e9;
    for(int prv=0; prv<level;prv++){
        ans = max(ans , rec(prv)+1);
    }
    
    return dp[level] = ans;
    
}
int main(){
    int n;
    cin>>n;
    arr.resize(n+1);
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    memset(dp , -1 , sizeof(dp));
    int ans = -1e9;

}