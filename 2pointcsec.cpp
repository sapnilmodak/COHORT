#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
int mod = 1e9 + 7;


void solution() {
    int n;
    cin>>n;
    int k;
    cin>>k;
    std::vector<int>arr(n);
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    int tail =0;
    int head =-1;
    map<int,int> freq;
    int ans = 0;
    while(tail < n){
        while(head +1 < n && (freq.size() < k || (freq.find(arr[head+1]) != freq.end()))){
            head++;
            freq[arr[head]]++;
            // cout<<arr[head]<<" ";
        }
        // for(auto k:freq){
        //     cout<<k.first<<" "<<k.second<<"fd ";
        // }
        // cout<<"fds ";
        // cout<<freq.size()<<" ";
        ans += (head - tail +1);
        // cout<<head<<" "<<tail<<'\n';
        if(tail > head){
            tail++;
            head = tail -1;
        }
        else {
           freq[arr[tail]]--;
           if(freq[arr[tail]] == 0){
               freq.erase(arr[tail]);
           }
           tail++;
        }
        
    }
      cout<<ans<<'\n';
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solution();
    return 0;
}
