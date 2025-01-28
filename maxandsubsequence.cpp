#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
int mod = 1e9 + 7;
#define ll long long;

void solution() {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int k;
        cin>>k;
        std::vector<int>arr(n);
        for(int i=0; i<n; i++){
            cin>>arr[i];
        }
        int ans = 0;
        for(int i=29; i>=0; i--){
            vector<int> newelements;
            for(auto v:arr){
                if((v>>i)&1){
                    newelements.push_back(v);
                }
            }
            if(newelements.size() >= k){
                ans += (1ll<<i);
                arr = newelements;
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
