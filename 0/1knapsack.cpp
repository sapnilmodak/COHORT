#include <bits/stdc++.h>
using namespace std;
int knapsack(std::vector<int>wt , vector<int> val , int n , int maxweight){
    vector<vector<int>> dp(n , vector<int> (maxweight+1 , 0));
    for(int w = wt[0]; w <= maxweight; w++) dp[0][w] = val[0];
    
    for(int ind=1; ind<n;ind++){
        for(int w=0; w<=maxweight; w++){
            int nottake = 0 + dp[ind-1][w];
            int take = INT_MIN;
            if(wt[ind] <= w){
                take = val[ind] + dp[ind-1][w-wt[ind]];
                
            }
            dp[ind][w] = max(take , nottake);
        }
    }
    return dp[n-1][maxweight];
}
int main(){
    int n;
    cout<<"enter no of val";
    cin>>n;
    int W;
    cout<<"enter max maxweight"<<'\n';
    cin>>W;
    vector<int> wt(n);
    vector<int>val(n);
    cout<<"enter wt"<<'\n';
    for(int i=0; i<n; i++){
        cin>>wt[i];
    }
    cout<<"enter the value"<<'\n';
    for(int i=0; i<n; i++){
        cin>>val[i];
    }
    int ans = knapsack(wt , val , n ,W);
    cout<<"enter the val"<<ans<<'\n';
}