#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
int mod = 1e9 + 7;
#define ll long long;
int addMod(int a,int b){
   a = a+b;
   if(a>=mod)
       a-=mod;
   return a;
}
int sumxor(vector<int> arr , int n){
    int ans = 0;
    for(int j=0; j<31; j++){
        int cnt[2];
        cnt[0]=cnt[1]=0;
        for(int i=0; i<n; i++){
            cnt[(arr[i]>>j&1)]++;
        }
        int num = (cnt[1]*cnt[0])%mod;
        ans += num * (1ll<<j);
    }
    return ans%mod;
}
int sumand(vector<int> arr , int n){
    int ans = 0;
    for(int j=0; j<31; j++){
        int cnt[2];
        cnt[0]=cnt[1]=0;
        for(int i=0; i<n; i++){
            cnt[(arr[i]>>j&1)]++;
        }
        int num = (cnt[1]*(cnt[1]-1)/2)%mod;
        ans += (num * (1ll<<j))%mod;
    }
    return ans%mod;
}
int sumsubsetxor(int n , vector<int> arr){
    
   int ans = 0;
    for(int j=0; j<31; j++){
        int cnt[2];
        cnt[0]=cnt[1]=0;
        for(int i=0; i<n; i++){
            cnt[((arr[i]>>j)&1)]++;
        }
        ans = addMod(ans ,( (1<<(n-1)) * (1ll<<j)%mod)%mod);
    }
    return ans%mod;
}


void solution() {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        std::vector<int>arr(n);
        for(int i=0; i<n; i++){
            cin>>arr[i];
        }
        int a,b,c,d;
        a = sumxor(arr , n);
        b = sumsubsetxor(n , arr);
        c = sumand(arr , n);
        cout<<a<<" "<<b<<" "<<c<<" "<<d<<'\n';
        
        
    }
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solution();
    return 0;
}
