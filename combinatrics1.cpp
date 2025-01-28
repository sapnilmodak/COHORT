#include <bits/stdc++.h>
using namespace std;
#define int long long
int mod = 1e9 +7;
int factu(int n){
    int ans=1;
    for(int i=1; i<=n; i++){
        ans = (ans*i)%mod;
    }
    return ans;
}
int binpower(int a,int  b){
    if(b==0){
        return 1;
    }
    else if(b%2 == 1){
        return a * binpower(a,b-1);
    }
    else {
        int x = binpower(a,b/2);
        return x*x;
    }
}
int inverse(int x){
    return binpower(x,mod-2);
}
int ncr_single(int n ,  int r){
    int num=1;
    int dec=1;
    for(int i=1; i<=r; i++){
        num = (num*(n-i+1))%mod;
        dec = (dec*i)%mod;
    }
    return (num*inverse(dec))%mod;
}
int ncr_basic(int n,int r){
    //for ranging n<=40
    int ans=1;
    for(int i=1; i<=r; i++){
        ans = ans*(n-i+1)%mod;
        ans = (ans/i)%mod;
    }
    return ans;
}
int ncr[1001][1001];
int ncr_random_modulo(int n,int r){
    ncr[0][0] = 1;
    for(int i=1;i<=n; i++){
        for(int j=0; j<=i; j++){
            if(j==0){
                ncr[i][j] = ncr[i-1][j]%mod;
            }
            else{
                ncr[i][j] = ncr[i-1][j] + ncr[i-1][j-1] %mod;
            }
        }
    }
    return ncr[n][r];
}
//MOST COMMMMMON
int fact[1000100];
int precompute(){
    fact[0] =1;
    for(int i=1; i<=1000000;i++){
        fact[i] = fact[i-1]* i %mod;
    }
}
int ncr_faster(int n,int r){
    int num = fact[n];
    int den = fact[n-r]*fact[r]%mod;
    return num*inverse(den)%mod;
}

signed main(){

}
