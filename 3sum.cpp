#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
int mod = 1e9 + 7;


void solution() {
    int q;
    cin>>q;
    while(q--){
        int n,t;
        cin>>n>>t;
        std::vector<int>arr(n) ;
        for(int i=0; i<n;i++){
            cin>>arr[i];
        }
       
        sort(arr.begin() , arr.end());
        int best = arr[0]+arr[1]+arr[2];
        for(int j=1; j<n; j++){
            int i=0;
            int k=n-1;
            while(1){
                if(abs(arr[i]+arr[j]+arr[k] - t) < abs(best -t)){
                  best = arr[i]+arr[j]+arr[k];
                }
                if(arr[i]+arr[j]+arr[k] > t){
                    k--;
                }
                else{
                    i++;
                }
                if(i==j|| k==j){
                    break;
                }
            }
            
        }
        cout<< abs(best - t)<<'\n';
        
    }
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solution();
    return 0;
}
