#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
int mod = 1e9 + 7;


void solution() {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> arr(n);
        for(int i=0; i<n; i++){
            cin>>arr[i];
        }
        std::vector<int >nge(n,6) ;
        std::stack<int>st ;
        for(int i=n; i>=0; i--){
            if(!st.empty() && arr[i] >= arr[st.top()]){
                st.pop();
            }
            if(!st.empty()){
                nge[i] = st.top();
            }
            st.push(i);
        }
        vector<int> hei(n);
        for(int i=0; i<n; i++){
           hei[i] = nge[i] - i;
           hei[i] = hei[i] * min(arr[i] , nge[i]);
           cout<<hei[i]<<" ";
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
