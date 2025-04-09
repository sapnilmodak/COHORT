/*
You are given an array arr of integers of length n. Your task is to partition the array into exactly k non-overlapping contiguous segments. For each segment, compute the minimum element in that segment. Your goal is to minimize the total sum of these minimum elements across all k segments.
*/
#include <bits/stdc++.h>
using namespace std;
vector<int> arr;
int dp[1001][1001]; // dp[level][k] = min sum of minimums for first level elements with k segments
int n,k;
int rec(int level , int k){
    //prune
    if(k < 0){
        return 1e9;
    }
    //base
    if(level == -1){
        if(k==0){
            return 0;
        }
        else{
            return 1e9;
            
        }
    }
    //cache
    if(dp[level][k] != -1){
        return dp[level][k];
    }
    int min_seen = arr[level];
    int ans = 1e9;
    //transaction
    for(int j=level-1; j>=-1; j--){
        ans = min( ans , rec(j , k-1) + min_seen);
        //crazy line h
        min_seen = min( min_seen , arr[j]);
    }
    //return
    return dp[level][k] = ans;
    
    
}

int main(){
    cin>>n>>k;
    arr.resize(n);
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    
    memset(dp , -1 , sizeof(dp));
    int ans = rec(n-1 , k);
    cout<<ans<<endl;
    return 0;
}