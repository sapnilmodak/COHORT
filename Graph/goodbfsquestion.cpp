/*you have given a start and end string and some banned string and in one step 
you can change only one bit of start such tht it shouldnt be any of string in banned strings
eg: 101 -> 000 and banned string are 001 and 100
step 1: 111
step 2: 011
step 3: 010
step 4: 000 so answer is 4 
*/ 
#include <bits/stdc++.h>
using namespace std;

unordered_set<int> mt; // Using unordered_set instead of multiset
vector<int> dis;

int stringtoint(string s) {
    int ans = 0;
    for (int i = 0; i < 21; i++) {
        if (s[i] == '1') {  
            ans |= (1 << (20 - i));
        }
    }
    return ans;
}

void bfs(int node) {
    dis[node] = 0;
    queue<int> q;
    q.push(node);

    while (!q.empty()) {
        int curr = q.front();
        q.pop();

        for (int i = 0; i < 21; i++) {
            int next = curr ^ (1 << i);
            if (mt.find(next) == mt.end()) {  
                if (dis[next] > dis[curr] + 1) { 
                    dis[next] = dis[curr] + 1;
                    q.push(next);
                }
            }
        }
    }
}

int main() {
    string st, en;
    cin >> st >> en;

    dis.assign(1 << 21, 1e9);  
    int s = stringtoint(st);
    int e = stringtoint(en);

    int m;
    cin >> m;
    while (m--) {
        string c;
        cin >> c;
        mt.insert(stringtoint(c));
    }

    bfs(s);

    cout << (dis[e] == 1e9 ? -1 : dis[e]) << '\n';  
}
