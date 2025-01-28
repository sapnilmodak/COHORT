#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
int mod = 1e9 + 7;
int board[14][14];
int n=3;
int k;
int ans;
int dx[8] = {2,2,-2,-2, 1,-1,1,-1};
int dy[8] = {-1 ,+1,+1,-1 ,2,2,-2,-2};
bool check(int row , int col){
    if(board[row][col] == 1) return 0;
    for(int i=0; i<8; i++){
        int nx = row + dx[i];
        int ny = col + dy[i];
        if(nx<n&&ny<n && nx>=0&& ny>=0 && board[nx][ny] == 1) return 0;
    }
    return 1;
}
void rec(int level){//level is the number of knight
    if(level == k){
        ans++;
        return;
    }
    //choice is whole board of chess which is nxn
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(check(i , j)){
                board[i][j] = 1;
                rec(level+1);
                board[i][j] = 0;
            }
        }
    }
}

void solution() {
    cin>>k;
    ans =0;
    rec(0);
    for(int i=1; i<=k; i++) ans = ans/i;
    cout<<ans<<'\n';
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solution();
    return 0;
}
