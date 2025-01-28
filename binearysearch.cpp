#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
int mod = 1e9 + 7;


bool check(int x,vector<int> arr , int n, int k){
    int cnt =0;
    for(int i=0; i<n; i++){
        int ne = x/arr[i];
        cnt += upper_bound(arr.begin() , arr.end() , ne) - arr.begin();
        
        
    }
    return cnt >= k;
}

void solution() {
    int n,k;
    cin>>n>>k;
    std::vector<int>arr(n) ;
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    int  lo =arr[0]*arr[1];
   
    int hi = arr[n-1]*arr[n-2];
    int ans = 0;
    while(lo <= hi){
        int mid = (lo + hi)/2;
        if(check(mid,arr, n ,k)){
            hi = mid -1;
            ans = mid;
        }
        else{
            lo = mid +1;
        }
    }
    cout <<ans<<'\n';
    
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solution();
    return 0;
}
