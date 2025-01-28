#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
int mod = 1e9 + 7;


void solution() {
    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        vector<int> arr(n);
        for(int i=0;i<n; i++){
            cin>>arr[i];
        }
        int sum=0;
        int tail = 0;
        int head =-1;
        int ans =0;
        /* for every start*/
        while(tail<n){
            while(head+1 <n && /* put the condition */ (sum +  arr[head+1] <=k)){ 
                head++;
                /*insert into datastructure*/
                sum+=arr[head];
            }
            /* update the answer in current state*/
            ans += head-tail+1;
            /* move start one step forward*/
            if(tail>head){
                tail++;
                head = tail-1;
            }

            else{
                /* erease from tail */
                tail++;
                sum-=arr[tail-1];
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
