#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
int mod = 1e9 + 7;

bool check(int x, vector<int> arr , int n ,int k){
    int needed = 0;
    int left = 0;
    for(int i=0; i<n; i++){
        if(left >=arr[i]){
            left -= arr[i];
        }
        else{
            needed++;
            left += x - arr[i];
        }

        if(needed > k){
            return 0;
        }
    }
    if(needed > k){
        return 0;
    }
    else{
        return 1;
    }

}
void solution() {
    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        vector<int> arr(n);
        int lo=0;
        int hi = 0;
        for(int i=0; i<n;i++){
            cin>>arr[i];
            lo = max(lo , arr[i]);
            hi += arr[i];
        }
        int ans=0;
        while(lo <= hi){
            int mid = (lo + hi)/2;
            if(check(mid ,arr, n , k)){
                ans = mid;
                hi = mid -1;
            }
            else{
                lo = mid +1;
            }
        }
        cout<<ans<<'\n';
    }
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solution();
    return 0;
}
