#include <bits/stdc++.h>
using namespace std;

int n, m;
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
vector<string> g;
vector<vector<bool>> graph;
vector<vector<int>> distA;
vector<vector<int>> distMonst;
queue<pair<int, int>> Awala, Monstwala;
vector<vector<pair<int, int>>> parents;

int main() {
    cin >> n >> m;
    graph.assign(n, vector<bool>(m, true));
    distA.assign(n, vector<int>(m, -1));
    distMonst.assign(n, vector<int>(m, -1));
    parents.assign(n, vector<pair<int, int>>(m, {-1, -1}));

    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < m; j++) {
            if (s[j] == '#') {
                graph[i][j] = false;
            } else if (s[j] == 'M') {
                distMonst[i][j] = 0;
                Monstwala.push({i, j});
            } else if (s[j] == 'A') {
                distA[i][j] = 0;
                Awala.push({i, j});
            }
        }
    }

    // BFS for monsters
    while (!Monstwala.empty()) {
        auto [x, y] = Monstwala.front();
        Monstwala.pop();
        for (int i = 0; i < 4; i++) {
            int xx = x + dx[i];
            int yy = y + dy[i];
            if (xx >= 0 && xx < n && yy >= 0 && yy < m && graph[xx][yy] && distMonst[xx][yy] == -1) {
                Monstwala.push({xx, yy});
                distMonst[xx][yy] = distMonst[x][y] + 1;
            }
        }
    }

    // BFS for 'A'
    while (!Awala.empty()) {
        auto [x, y] = Awala.front();
        Awala.pop();
        for (int i = 0; i < 4; i++) {
            int xx = x + dx[i];
            int yy = y + dy[i];
            if (xx >= 0 && xx < n && yy >= 0 && yy < m && graph[xx][yy] && distA[xx][yy] == -1) {
                Awala.push({xx, yy});
                distA[xx][yy] = distA[x][y] + 1;
                parents[xx][yy] = {x, y};
            }
        }
    }

    int finx = -1, finy = -1, findist = 1e9;
    for (int i = 0; i < n; i++) {
        if (graph[i][0] && distA[i][0] != -1 && (distA[i][0] < distMonst[i][0] || distMonst[i][0] == -1)) {
            if (distA[i][0] < findist) {
                finx = i;
                finy = 0;
                findist = distA[i][0];
            }
        }
        if (graph[i][m - 1] && distA[i][m - 1] != -1 && (distA[i][m - 1] < distMonst[i][m - 1] || distMonst[i][m - 1] == -1)) {
            if (distA[i][m - 1] < findist) {
                finx = i;
                finy = m - 1;
                findist = distA[i][m - 1];
            }
        }
    }
    for (int j = 0; j < m; j++) {
        if (graph[0][j] && distA[0][j] != -1 && (distA[0][j] < distMonst[0][j] || distMonst[0][j] == -1)) {
            if (distA[0][j] < findist) {
                finx = 0;
                finy = j;
                findist = distA[0][j];
            }
        }
        if (graph[n - 1][j] && distA[n - 1][j] != -1 && (distA[n - 1][j] < distMonst[n - 1][j] || distMonst[n - 1][j] == -1)) {
            if (distA[n - 1][j] < findist) {
                finx = n - 1;
                finy = j;
                findist = distA[n - 1][j];
            }
        }
    }

    if (finx == -1) {
        cout << "NO" << '\n';
    } else {
        cout << "YES" << '\n';
        cout << findist << '\n';
    }

    return 0;
}
