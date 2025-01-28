#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
int mod = 1e9 + 7;


void solution() {
    int n;
    cin>>n;
    std::vector<int>arr(n);
    vector<int> cnt(21);
    for(int i=0; i<n; i++){
        cin>>arr[i];
        for(int j=0; j<21; j++){
            if(arr[i]&(1<<j)){
                cnt[j]++;
            }
        }
    }
    int ans = 0;
    for(int i=0; i<n; i++){
        int large =0;
        for(int j=0; j<21; j++){
            if(cnt[j]){
                large |= (1<<j);
                cnt[j]--;
            }
        }
        ans += large*large;
    }
    cout<<ans<<'\n';
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solution();
    return 0;
}
