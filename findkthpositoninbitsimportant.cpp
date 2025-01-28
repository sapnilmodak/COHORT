#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"

int mod = 1e9 + 7;

// Function to get the binary representation of a number as a string
string get_bits_string(int x) {
    string cnt = "";
    while (x) {
        cnt += (x % 2 == 0) ? '0' : '1';
        x /= 2;
    }
    reverse(cnt.begin(), cnt.end());
    return cnt.empty() ? "0" : cnt;
}

// Function to calculate the total number of 1-bits in binary representations from 0 to x
int sum_one_bits(int x) {
    int ans = 0;
    int total = x + 1;
    for (int i = 0; i < 60; i++) {
        int full = (total / (1LL << (i + 1)));
        int left = (total % (1LL << (i + 1)));
        int extra = max(left - (1LL << i), 0LL);
        ans += full * (1LL << i) + extra;
    }
    return ans;
}

// Function to find the smallest number whose cumulative 1-bits exceed x
int find_kth_one(int x) {
    int lo = 0;
    int hi = x;
    int ans = -1;
    while (lo <= hi) {
        int mid = (lo + hi) / 2;
        if (sum_one_bits(mid) > x) {
            ans = mid;
            hi = mid - 1;
        } else {
            lo = mid + 1;
        }
    }
    return ans;
}

// Function to find the position of the k-th 1 in the binary representation of x
int find_pos_kth_one_innum(int x, int k) {
    string s = get_bits_string(x);
    int cnt = 0;
    int i;
    for (i = 0; i < s.size(); i++) {
        if (s[i] == '1') {
            cnt++;
        }
        if (cnt == k) {
            break;
        }
    }
    return i;
}

// Function to calculate the total length of concatenated binary strings from 1 to x
int total_bit_len(int x) {
    int ans = 0;
    int len = 1;
    int num = 1;
    while (num <= x) {
        int sametill = (num * 2) - 1;
        if (sametill <= x) {
            ans += len * (sametill - num + 1);
            num = sametill + 1;
            len++;
        } else {
            ans += len * (x - num + 1);
            break;
        }
    }
    return ans;
}

// Solution function to handle queries
void solution() {
    int q;
    cin >> q;
    while (q--) {
        int x;
        cin >> x;
        int num = find_kth_one(x);
        cout << "Number containing the x-th 1: " << num << '\n';

        int pos_in_num = x - sum_one_bits(num - 1);
        cout << "Position in the number: " << pos_in_num << '\n';

        int index = find_pos_kth_one_innum(num, pos_in_num);
        cout << "Index in binary concatenation: " << total_bit_len(num - 1) + index << '\n';
    }
}

// Main function
signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solution();
    return 0;
}
