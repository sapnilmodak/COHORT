#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
int mod = 1e9 + 7;
const int boardsize =  4;
const int cellsize =2;
int board[boardsize][boardsize];
int ans;
int log2arr[10010];
int takenrow[boardsize];
int takencol[boardsize];
int takengrid[cellsize][cellsize];
void printing(int board[boardsize][boardsize]){
    for(int i=0; i<boardsize; i++){
        for(int j=0; j<boardsize; j++){
            cout<<board[i][j]<<" ";
        }
        cout<<'\n';
    }
}
void makemove(int ch , int row , int col){
    board[row][col] = ch;
    takenrow[row] ^=(1<<ch);
    takencol[col] ^= (1<<ch);
    takengrid[row/cellsize][col/cellsize] ^= (1<<ch);
    
}
void revertmove(int ch , int row , int col){
    board[row][col] = 0;
    takenrow[row] ^=(1<<ch);
    takencol[col] ^= (1<<ch);
    takengrid[row/cellsize][col/cellsize] ^= (1<<ch);
}
int getchoices(int row , int col){
    int taken = (takenrow[row] | takencol[col] | takengrid[row/cellsize][col/cellsize]);
    int nottaken = (1<<(boardsize+1)-1)^taken;
    if(nottaken&1) nottaken^=1;
    return nottaken;
}
void rec(int row , int col){
    if(col == boardsize){
        rec(row+1, 0);
        return;
    }
    if(row == boardsize){
        ans++;
        printing(board);
        return;
    }
    if(board[row][col] == 0){
       int chmask = getchoices(row , col);
       while(chmask){
           int last1 =  chmask^(chmask&chmask-1);
           int last1pos = log2arr[last1];
           makemove(last1pos, row , col);
           rec(row , col+1);
           revertmove(last1pos , row , col);
           
           chmask  = chmask&(chmask-1);
       }
    }
    else{
        rec(row,col+1);
    }
}

void solution() {
    for(int i=0; i<=9; i++){
        log2arr[1<<i] = i;
    }
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
