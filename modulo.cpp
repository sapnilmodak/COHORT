#include <bits/stdc++.h>
using namespace std;
#define int long long
int mod = 1e9 + 7;

int binpower(int a, int b){
    if(b==0){
        return 1;
    }
    if(b%2 == 1){
        return a * binpower(a,b-1) % mod; 
    }
    else{
        int x = binpower(a,b/2);
        return (x*x)%mod;
    }
}


signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int a,b,c,d,e,f;
    cin>>a>>b>>c>>d>>e>>f;
    //(a+b - c* e^d + f)%mod
    int ans = binpower(e,d);
    ans = (c%mod) * ans%mod;
    ans = (b%mod - ans)%mod;
    ans = (a%mod + ans)%mod;
    ans= (ans +f%mod)%mod;
    cout<<( ans%mod + mod)%mod<<"\n";


    return 0;
}