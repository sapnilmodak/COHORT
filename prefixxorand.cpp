#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
#define ll long long
int mod = 1e9 + 7;

void solution() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

       
        vector<vector<int>> ps(n, vector<int>(31, 0));

        
        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            int cnt = 0;

            while (x) {
                ps[i][cnt] = x % 2;
                x /= 2;
                cnt++;
            }
        }

   
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < 31; j++) {
                ps[i][j] += ps[i - 1][j];
            }
        }

        int q;
        cin >> q;
        while (q--) {
            int l, r;
            cin >> l >> r;
            l--; r--; 
            int a = 0, b = 0, c = 0;
            int total = (r - l + 1) / 2;

            for (int i = 0; i < 31; i++) {
                int p = ps[r][i] - (l > 0 ? ps[l - 1][i] : 0);

                if (p < (r - l + 1) - p) { 
                    a += (1LL << i);
                }
                if (p != (r - l + 1)) {    
                    b += (1LL << i);
                }
                if (p > 0) {              
                    c += (1LL << i);
                }
            }

            cout << a + b + c << '\n';
        }
    }
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solution();
    return 0;
}
