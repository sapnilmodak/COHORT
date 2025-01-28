#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
int mod = 1e9 + 7;

void kthmove(int disc , int source , int target , int aux , int k){
    if(k <= ((1<<(disc-1))-1){
        kthmove(disc-1 , source , target , aux , k);
    }
    else if(k == (1<<(disc-1))){
        cout<<"moving disc to "<<disc<<"from"<<source<<" to "<<target<<'\n';
    }
    else{
        kthmove(disc-1 , aux , target , source , k - (1<<(disc-1)));
    }
}
void solution() {
    
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solution();
    return 0;
}
