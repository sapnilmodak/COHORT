/*this is knapsach problem where you can at most take K item such that the sum of wieght of the item is divisible by M
genrate all the values which you choose
*/
#include <bits/stdc++.h>
using namespace std;
vector<int> w;
vector<int> v;
vector<int> solution;
int dp[3003][3003][100];
int n,W,K,M;
int rec(int l , int x , int itemleft){
    //pruning
    //basecase
    if(l == n){
       int sum_of_take = (W - x);
       if(sum_of_take%M == 0){
           return 0;
       }
       else{
           return -1e9;
       }
    }
    //cache
    if(dp[l][x][itemleft] != -1){
        return dp[l][x][itemleft];
    }
    //transition
    int ans = rec(l +1 , x , itemleft);
    if(w[l] <= x && itemleft>0){
        ans = max(ans , rec(l , x - w[l] , itemleft-1) + v[l]);
    }
    return dp[l][x][itemleft] = ans;
}
void genrate(int l , int x , int itemleft){
    if(l == n){
        return;
    }
    else{
        int donttake = rec(l+1 , x , itemleft);
        if(w[l] <= x && itemleft>0){
            int take = rec(l , x- w[l] , itemleft-1) + v[l];
            if(donttake > take){
                genrate( l+1 , x , itemleft);
            }
            else{
                solution.push_back(v[l]);
                genrate( l+1 , x - w[l] , itemleft-1);
            }
        }
        else{
            genrate(l+1 , x , itemleft);
        }
    }
    
}
int main(){
   cin>>n;
   w.resize(n+1);
   v.resize(n+1);
   for(int i=1 ; i<=n; i++){
       cin>>w[i]>>v[i];
   }
   cin>>W>>K>>M;
    memset(dp , -1 , sizeof(dp));
    cout<<rec(0 , W , K)<<'\n';
    genrate(0 , W , K);
}