// For the given n, consider the array A = {1, 2, …, n}. There exist n! unique permutations of the array. When we list all these n! permutations in lexicographically order, your task is to find kth permutation in that list.
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"

int mod = 1e9 + 7;
int n, k;
vector<int> a;
int fact[14]; 

void Fact() {
    fact[0] = 1;
    for (int i = 1; i <= 13; i++) {
        fact[i] = fact[i - 1] * i;
    }
}

void kth_permutation() {
    vector<int> ans;
    k--; 
    while (true) {
        int s = a.size();
        ans.push_back(a[k / fact[s - 1]]);
        a.erase(a.begin() + k / fact[s - 1]);
        if (a.empty()) break;
        k %= fact[s - 1];
    }
    for (auto it : ans) cout << it << " ";
    cout << endl;
}

void solution() {
    Fact();
    cin >> n >> k;
    if (n <= 13) {
        for (int i = 1; i <= n; i++) a.push_back(i);
        kth_permutation();
    } else {
        for (int i = 1; i < n - 12; i++) cout << i << " ";
        for (int i = n - 12; i <= n; i++) a.push_back(i);
        kth_permutation();
    }
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solution();
    return 0;
}
