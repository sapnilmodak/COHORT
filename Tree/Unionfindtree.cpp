#include <bits/stdc++.h>
using namespace std;
int n;
int par[10010];
int ranked[10010];
int set_size;
void unionfind(int x){
    set_size = n;
    for(int i=1; i<=n; i++) par[i] =i;
    
    for(int i=1; i<=n; i++) ranked[i] =1;
}
int find(int x){
    if(par[x] == x) return x;
    
    else{
        return par[x] = find(par[x]);
    }
}
void merge(int x , int y){
    int x_root = find(x);
    int y_root = find(y);
    if(x_root != y_root){
        if(ranked[x_root] > ranked[y_root]){
            ranked[x_root] += ranked[y_root];
            par[y_root] = x_root;
        }
        else{
            ranked[y_root] += ranked[x_root];
            par[x_root] = y_root;
        }
        set_size--;
    }
}
void reset(){
    set_size = n;
    for(int i=1; i<=n; i++) par[i] =i;
    
    for(int i=1; i<=n; i++) ranked[i] =1;
}
int main(){
    cin>>n;
    
}