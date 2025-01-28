#include<bits/stdc++.h>
using namespace std;

#define F first
#define S second
#define INF 1e9
using ii = pair<int,int>;
using state = pair<pair<int,int>,int>;

int n,m;
vector<string> arr;

vector<vector<vector<int>>> dis;

int dx[] = {1,0,-1,0};
int dy[] = {0,1,0,-1};

bool inside(int x,int y){
    if(x>=0&&x<n&&y>=0&&y<m&&arr[x][y]!='#')return 1;
    return 0;
}

vector<state> getneighbour(state cur){ 
    vector<state> ans;
    for(int dir=0;dir<4;dir++){
        int x = cur.F.F + dx[dir];
        int y = cur.F.S + dy[dir];
        if(!inside(x,y))continue;
        int z = cur.S;
        if(arr[x][y]=='P')z=1;
        ans.push_back({{x,y},z});
    }
    return ans;
}

vector<vector<vector<ii>>> origin;
vector<vector<vector<ii>>> ptaken;

void bfs(vector<ii> en){
    dis = vector<vector<vector<int>>>(n, 
            vector<vector<int>>(m, 
                vector<int>(2,INF)
            )
        );
        
    origin = vector<vector<vector<ii>>>(n, 
            vector<vector<ii>>(m, 
                vector<ii>(2,{-1,-1})
            )
        );
        
    ptaken = vector<vector<vector<ii>>>(n, 
            vector<vector<ii>>(m, 
                vector<ii>(2,{-1,-1})
            )
        );
    
    queue<state> q;
    for(auto en_pos:en){
        q.push({en_pos,0});
        dis[en_pos.F][en_pos.S][0] = 0;
        origin[en_pos.F][en_pos.S][0] = en_pos;
    }
    while(!q.empty()){
        state cur = q.front(); q.pop();
        for(auto v:getneighbour(cur)){
            if(dis[v.F.F][v.F.S][v.S] > dis[cur.F.F][cur.F.S][cur.S] + 1){
                dis[v.F.F][v.F.S][v.S] = dis[cur.F.F][cur.F.S][cur.S] + 1;
                origin[v.F.F][v.F.S][v.S] = origin[cur.F.F][cur.F.S][cur.S];
                ptaken[v.F.F][v.F.S][v.S] = ptaken[cur.F.F][cur.F.S][cur.S];
                if(arr[v.F.F][v.F.S]=='P') ptaken[v.F.F][v.F.S][v.S]  = {v.F.F,v.F.S};
                q.push(v);
            }   
        }
    }
}    


int main(){
    cin>>n>>m;
    arr.resize(n);
    
    vector<ii> st,en;
    for(int i=0;i<n;i++){
        cin>>arr[i];
        for(int j=0;j<m;j++){
            if(arr[i][j]=='S'){
                st.push_back({i,j});
            }else if(arr[i][j]=='F'){
                en.push_back({i,j});
            }
        }
    }

    bfs(en);
    for(auto v:st){
        cout<<v.F<<","<<v.S<<" : "
            <<origin[v.F][v.S][1].F<<" "<<origin[v.F][v.S][1].S<<" "
            <<ptaken[v.F][v.S][1].F<<" "<<ptaken[v.F][v.S][1].S<<" "
            <<dis[v.F][v.S][1]<<endl;
    }
    return 0;
}

/*
6 6
S..P.F
....#.
....#.
....F.
......
PS....
*/
//find a path from each  s to F such that they visit a P