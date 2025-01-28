#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
const int INF = 1e9;
using state = pair<int, int>; // Fix: Proper type alias syntax

vector<vector<char>> arr;
vector<vector<int>> dis;
vector<vector<state>> par;
queue<state> q; // Fix: Define queue here

#define F first
#define S second

int dx[] = {-1, +1, 0, 0};
int dy[] = {0, 0, -1, +1};

bool isvalid(int x, int y, int n, int m) { // Add `n` and `m` for boundary checks
    return (x >= 0 && x < n && y >= 0 && y < m && arr[x][y] != '#');
}

vector<state> neighbour(state node, int n, int m) {
    vector<state> ans;
    for (int i = 0; i < 4; i++) {
        int x = node.F + dx[i];
        int y = node.S + dy[i];
        if (isvalid(x, y, n, m)) {
            ans.push_back({x, y});
        }
    }
    return ans;
}

void bfs(state st_node, int n, int m) {
    par[st_node.F][st_node.S] = {-1, -1};
    dis[st_node.F][st_node.S] = 0;
    q.push(st_node);

    while (!q.empty()) {
        state node = q.front(); // Fix: Add parentheses for `q.front()`
        q.pop();

        for (state v : neighbour(node, n, m)) {
            if (dis[v.F][v.S] == INF) {
                q.push(v);
                dis[v.F][v.S] = dis[node.F][node.S] + 1;
                par[v.F][v.S] = node;
            }
        }
    }
}

void solution() {
    int n, m;
    cin >> n >> m;
    arr.resize(n);
    dis.assign(n, vector<int>(m, INF)); // Fix: Properly initialize `dis`
    par.assign(n, vector<state>(m, {-1, -1})); // Fix: Properly initialize `par`

    state st, en;

    for (int i = 0; i < n; i++) {
        arr[i].resize(m);
        for (int j = 0; j < m; j++) {
            cin >> arr[i][j];
            if (arr[i][j] == 'S') {
                st = {i, j};
            } else if (arr[i][j] == 'F') {
                en = {i, j};
            }
        }
    }

    bfs(st, n, m);

    if (dis[en.F][en.S] == INF) {
        cout << "No path found" << endl;
        return;
    }

    cout << dis[en.F][en.S] << '\n';

    vector<state> path;
    state curr = en;

    while (curr != make_pair(-1LL, -1LL)) {
    path.push_back(curr);
    curr = par[curr.F][curr.S];
    }

    reverse(path.begin(), path.end());

    for (auto v : path) {
        cout << v.F << " " << v.S << '\n';
    }
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solution();
    return 0;
}
// 5 8
// ########
// #S.....#
// ###.####
// #.....F#
// ########
