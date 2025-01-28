#include<bits/stdc++.h>
using namespace std;
#define int long long
int mod = 1e9+7;

int fact1(int x){
    int ans = 1;
    for(int i=1;i<=x;i++){
        ans = (ans * i)%mod;
    }
    return ans;
}

int binpow(int a,int b){
    if(b==0)return 1;
    if(b%2==1){
        return (a*binpow(a,b-1))%mod;
    }
    else{
        int x = binpow(a,b/2);
        return (x*x)%mod;
    }
}

int inverse(int x){// O(log(mod))
    return binpow(x,mod-2);
}

int ncr_single(int n,int r){ //O(r)
    int num = 1;
    int den = 1;
    for(int i=1;i<=r;i++){
        num = num*(n-i+1)%mod;
        den = den*i%mod;
    }
    return (num*inverse(den))%mod;
}

int ncr_basic(int n,int r){ // Works for n<=40
    int ans = 1;
    for(int i=1;i<=r;i++){
        ans = ans*(n-i+1);
        ans = ans/i;
    }
    return ans;
}

int ncr[1001][1001];
int ncr_random_modulo(int n,int r){
    ncr[0][0]=1;
    for(int i=1;i<=n;i++){
        for(int j=0;j<=i;j++){
            if(j==0)ncr[i][j] = (ncr[i-1][j])%mod;
            else ncr[i][j] = (ncr[i-1][j-1] + ncr[i-1][j])%mod;
        }
    }
    return ncr[n][r];
}

// MOST COMMON
int fact[1000100];
void precompute(){
    fact[0] = 1;
    for(int i=1;i<=1000000;i++){
        fact[i] = fact[i-1]*i%mod;
    }
}
int ncr_fact(int n,int r){ // O(log(mod))
    int num = fact[n];
    int den = fact[n-r]*fact[r]%mod;
    return (num*inverse(den))%mod;
}


// EVEN FASTER

int fact[1000100];
int invfact[1000100];
void precompute_for_faster(){
    fact[0] = 1;
    for(int i=1;i<=1000000;i++){
        fact[i] = fact[i-1]*i%mod;
    }
    invfact[1000000] = inverse(fact[1000000]);
    for(int i=1000000;i>=1;i--){
        invfact[i-1] = invfact[i] *i%mod;
    }
}
int ncr_fact_faster(int n,int r){ // O(1)
    int num = fact[n];
    int den = invfact[n-r]*invfact[r]%mod;
    return (num*den)%mod;
}


signed main()
{
    precompute();
    int q;
    cin>>q;
    while(q--){
        int n,r;
        cin>>n>>r;
        cout<<ncr_fact(n,r)<<endl;
    }

    return 0;
}