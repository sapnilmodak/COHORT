#include <bits/stdc++.h>
using namespace std;
vector<vector<char>> g;
using state = pair<int,int>;
vector<vector<int>> dis;
int n,m;
int dx[] = {-1,1,0,0};
int dy[] = {0,0,-1,1};
bool isvalid(int x , int y){
    if(x>=0 && x<n && y>=0 && y <m) return 1;
    
    return 0;
}
void bfs(state node){
    dis[node.first][node.second] =0;
    deque<state> dq;
    dq.push_back(node);
    while(!dq.empty()){
        state curr =dq.front();
        dq.pop_back();
        for(int k=0; k<4; k++){
            int xx = curr.first + dx[k];
            int yy = curr.second + dy[k];
            if(isvalid(xx,yy) ){
                if(g[curr.first][curr.second] =='d' && dx[k]==0 && dy[k] == 1){
                   if(dis[xx][yy] > dis[curr.first][curr.second]){
                        dis[xx][yy]  = dis[curr.first][curr.second];
                        dq.push_front({xx,yy});
                   }
                }
                else if(g[curr.first][curr.second] =='w' && dx[k]==-1&& dy[k] == 0){
                    if(dis[xx][yy] > dis[curr.first][curr.second]){
                        dis[xx][yy]  = dis[curr.first][curr.second];
                        dq.push_front({xx,yy});
                   }
                }
                else if(g[curr.first][curr.second] =='a' && dx[k]==0 && dy[k] == -1){
                   if(dis[xx][yy] > dis[curr.first][curr.second]){
                        dis[xx][yy]  = dis[curr.first][curr.second];
                        dq.push_front({xx,yy});
                   }
                }
                else if(g[curr.first][curr.second] =='s' && dx[k]==1 && dy[k] == 0){
                    if(dis[xx][yy] > dis[curr.first][curr.second]){
                        dis[xx][yy]  = dis[curr.first][curr.second];
                        dq.push_front({xx,yy});
                   }
                }
                else{
                   if(dis[xx][yy] > dis[curr.first][curr.second] +1){
                        dis[xx][yy]  = dis[curr.first][curr.second]+1;
                        dq.push_back({xx,yy});
                   }
                }
            }
        }
    }
}

int main(){
    cin>>n>>m;
    g.resize(n);
    dis.assign( n , vector<int> (m , 1e9));
    for(int i=0; i<n; i++){
        g[i].resize(m);
        for(int j=0; j<m; j++){
            cin>>g[i][j];
        }
    }
    bfs({0,0});
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cout<<dis[i][j]<<" ";
        }
        cout<<'\n';
    }
    
}
/*
w - upper s- down d- right a-left
3  3
d d s
w s a 
w d d
you have to go to (1,1) to (n,n)
*/