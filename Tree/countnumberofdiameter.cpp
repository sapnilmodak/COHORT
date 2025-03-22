#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> ans;
vector<vector<int>> g;
int par[200010];
int depth[200010];
int diameter;
int cnt;

void dfs(int node, int parent, int dep) {
    depth[node] = dep;
    par[node] = parent;
    for (auto v : g[node]) {
        if (v != parent) {
            dfs(v, node, dep + 1);
        }
    }
}

int find_center(int len, int node) {
    int x = (len / 2);
    while (x-- && node != 0) {
        node = par[node];
    }
    return node;
}

void count_nodes(int node, int parent, int dep, int target_depth) {
    if (dep == target_depth) cnt++;
    for (auto v : g[node]) {
        if (v != parent) {
            count_nodes(v, node, dep + 1, target_depth);
        }
    }
}

int main() {
    cin >> n;
    g.resize(n + 1);

    for (int i = 1; i <= n - 1; i++) {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    dfs(1, -1, 0);
    int maxnum = 1;
    for (int j = 2; j <= n; j++) {
        if (depth[maxnum] < depth[j]) {
            maxnum = j;
        }
    }

    dfs(maxnum, -1, 0);
    maxnum = 1;
    for (int j = 2; j <= n; j++) {
        if (depth[maxnum] < depth[j]) {
            maxnum = j;
        }
    }
    diameter = depth[maxnum];

    int center = find_center(diameter, maxnum);

    if (diameter % 2 == 1) {
        int c2 = par[center];
        int cnt1 = 0, cnt2 = 0;

        cnt = 0;
        count_nodes(center, c2, 0, diameter / 2);
        cnt1 = cnt;

        cnt = 0;
        count_nodes(c2, center, 0, diameter / 2);
        cnt2 = cnt;

        cout << cnt1 * cnt2 << '\n';
    } else {
        ans.clear();
        for (auto v : g[center]) {
            cnt = 0;
            count_nodes(v, center, 0, (diameter / 2) - 1);
            ans.push_back(cnt);
        }

        int outty = 0;
        for (int i = 1; i < ans.size(); i++) {
            outty += ans[i] * ans[i - 1];
        }
        if (ans.size() > 2) {
            outty += ans[0] * ans[ans.size() - 1];
        }

        cout << outty << '\n';
    }
}
