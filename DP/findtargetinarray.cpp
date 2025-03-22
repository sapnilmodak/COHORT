#include<bits/stdc++.h>
using namespace std;
vector<int> arr;
int dp[1001][1001];
int n;
vector<int> solution;
int rec(int level , int sumleft){
    //pruning
    if(sumleft < 0){
        return 0;
    }
    //base
    if(level == n+1){
        if(sumleft == 0){
            return 1;
        }
        else{
            return 0;
        }
    }
    //cache
    if(dp[level][sumleft] != -1){
        return dp[level][sumleft];
    }
    //transaction
    int ans =0;
    if(rec(level+1 ,sumleft) == 1){
        ans= 1;
    }
    else if(rec(level+1, sumleft-arr[level])==1){
        ans=1;
    }
    //return
    return dp[level][sumleft] = ans;
}
void genrate(int level , int sumleft){
    if(level == n+1){
        return;
    }
    if(rec(level+1 , sumleft) == 1){
        genrate(level+1 , sumleft);
    }
    else if(rec(level+1 , sumleft-arr[level]) == 1){
        solution.push_back(arr[level]);
        genrate(level+1 , sumleft-arr[level]);
    }
}
int main(){
    cin>>n;
    arr.resize(n+1);
    for(int i=1; i<=n; i++){
        cin>>arr[i];
    }
    int q;
    memset(dp , -1 , sizeof(dp));
    cin>>q;
    while(q--){
        int t;
        cin>>t;
        cout<<rec(1,t)<<'\n';
        if(rec(1,t) == 1){
            solution.clear();
            genrate(1,t);
            for(auto x : solution){
                cout<<x<<' ';
            }
            cout<<'\n';
        }
    }
}
