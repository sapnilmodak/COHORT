/*
you want to travell from S to F by breaking <= k walls so this algo shows you the shortest path
*/

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
    if(x>=0&&x<n&&y>=0&&y<m)return 1;
    return 0;
}

vector<state> getneighbour(state cur){ 
    vector<state> ans;
    for(int dir=0;dir<4;dir++){
        int x = cur.F.F + dx[dir];
        int y = cur.F.S + dy[dir];
        if(!inside(x,y))continue;
        int z = cur.S;
        if(arr[x][y]=='#')z++;
        ans.push_back({{x,y},z});
    }
    return ans;
}

void bfs(state st){
    dis = vector<vector<vector<int>>>(n, 
            vector<vector<int>>(m, 
                vector<int>(n+m,INF)
            )
        );
    
    queue<state> q;
    dis[st.F.F][st.F.S][st.S] = 0;
    q.push(st);
    while(!q.empty()){
        state cur = q.front(); q.pop();
        for(auto v:getneighbour(cur)){
            if(dis[v.F.F][v.F.S][v.S] > dis[cur.F.F][cur.F.S][cur.S] + 1){
                dis[v.F.F][v.F.S][v.S] = dis[cur.F.F][cur.F.S][cur.S] + 1;
                q.push(v);
            }   
        }
    }
}    


int main(){
    cin>>n>>m;
    arr.resize(n);
    
    ii st,en;
    for(int i=0;i<n;i++){
        cin>>arr[i];
        for(int j=0;j<m;j++){
            if(arr[i][j]=='S'){
                st = {i,j};
            }else if(arr[i][j]=='E'){
                en = {i,j};
            }
        }
    }

    bfs({st,0});
    
    int minseen = INF;
    for(int k=0;k<n+m;k++){
        minseen = min(minseen,dis[en.F][en.S][k]);
        cout<<minseen<<endl;
    }
    return 0;
}

/*
6 6
.S#...
###.#.
###.#.
....#.
#####.
E.....
*/