#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
int mod = 1e9 + 7;
const int boardsize =  4;
const int cellsize =2;
int board[boardsize][boardsize];
int ans;
void printing(board){
    for(int i=0; i<boardsize; i++){
        for(int j=0; j<boardsize; j++){
            cout<<board[i][j]<<" ";
        }
        cout<<'\n';
    }
}
bool check(int row ,int col ,  int x){
    for(int i=0; i<boardsize; i++){
        if(board[row][i] == x) return false;
    }
    for(int i=0; i<boardsize; i++){
        if(board[i][col] == x) return false;
    }
    int nr = (row/cellsize)*cellsize;
    int nc = (col/cellsize)*cellsize;
    for(int dx=0; dx<cellsize; dx++){
        for(int dy =0; dy < cellsize; dy++){
            if(nr+dx == row && ny+dy == col) continue;
            if(board[nr+dx][ny+dy] == x) return false;
        }
    }
    return true;
    
}
void rec(int row , int col){
    if(col == boardsize){
        rec(row+1, 0);
        return;
    }
    if(row == boardsize){
        ans++;
        printint(board);
        return;
    }
    if(board[row][col] == 0){
        for(int ch=1; ch<=boardsize;ch++){
            if(check(row,col,ch)){
                board[row][col] =ch;
                rec(row , col+1);
                board[row][col] = 0;
            }
        }
    }
    else{
        if(check(row,col , board[row][col])){
            rec(row,col+1);
        }
    }
}

void solution() {
    ans =0;
    for(int i=0; i<boardsize; i++){
        for(int j=0; j<boardsize; j++){
            cin>>board[i][j];
        }
    }
    
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solution();
    return 0;
}
