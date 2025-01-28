#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
int mod = 1e9 + 7;
int n;
map<int,int>fq;
vector<vector<int>>arr;
vector<int>curr;
void rec(int level ){
    if(level == n){
        arr.push_back(curr);
        return;
    }
    for(auto it:fq){
        if(it.second > 0){
            int v = it.first;
            curr.push_back(v);
            fq[v]--;
            rec(level+1);
            curr.pop_back();
            fq[v]++;
        }
    }
    return;
}

void solution() {
    cin>>n;
    for(int i=0; i<n; i++){
        int x;
        cin>>x;
        fq[x]++;
    }
    rec(0);
    for(auto it:arr){
        for(auto q:it){
            cout<<q<<" ";
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
