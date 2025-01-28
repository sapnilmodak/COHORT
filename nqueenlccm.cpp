#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
int mod = 1e9 + 7;
int queen[13];
int n;
bool check(int row , int col){
    for (int i = 0; i < row; i++) {
        if (queen[i] == col || abs(row - i) == abs(col - queen[i])) {
            return false;
        }
    }
    return true;
}

int rec(int level){
    if(level == n){
        return 1;
    }
    int ans =0;
    for(int ch=0; ch<n; ch++){
        if(check(level , ch)){
            queen[level] = ch;
            ans += rec(level+1);
            queen[level] =-1;
        }
    }
    return ans;
    
}

void solution() {
   cin>>n;
   memset(queen , -1 ,sizeof(queen));
   cout<<rec(0)<<'\n';
    
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solution();
    return 0;
}
