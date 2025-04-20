/*
find maximum sum path from (0,0) to (n-1,m-1) in a grid, where you can only move down or right.
You can also add obstacles in the grid, which will block the path.
*/

#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> grid;
int n, m;
int dp[1001][1001];

int rec(int i, int j) {
    if (i == n - 1 && j == m - 1) return grid[i][j];

    if (dp[i][j] != -1) return dp[i][j];

    int ans = -1e9;

    if (i + 1 < n) {
        ans = max(ans, grid[i][j] + rec(i + 1, j));
    }

    if (j + 1 < m) {
        ans = max(ans, grid[i][j] + rec(i, j + 1));
    }

    return dp[i][j] = ans;
}

int main() {
    cin >> n >> m;
    grid.resize(n, vector<int>(m));
    
    for (int i = 0; i < n; i++) 
        for (int j = 0; j < m; j++) 
            cin >> grid[i][j];

    memset(dp, -1, sizeof(dp));
    cout << rec(0, 0) << '\n';
}
