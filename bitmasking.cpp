#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
int mod = 1e9 + 7;


void solution() {
    int n;
    cin>>n;
    std::vector<int>arr(n);
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    for(int mask=0; mask<(1<<n); mask++){
        cout<<mask<<": ";
        for(int i=0; i<n; i++){
            if(((mask>>i)&1) == 1){
                cout<<arr[i]<<", ";
            }
        }
        cout<<'\n';
    }
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solution();
    return 0;
}
