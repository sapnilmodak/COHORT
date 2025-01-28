/*
A Gray code is a list of all 2^n bit strings of length n, where any two successive strings differ in exactly one bit (i.e., their Hamming distance is one).
Your task is to create a Gray code for a given length n
*/
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
int mod = 1e9 + 7;


void solution() {
    int n;
    cin>>n;
    for(int i=0; i<(1<<n); i++){
        int x = (i^(i<<1));
        bitset<20>b(x);
        string s  =b.to_string();
        cout<<s.substr(20-n)<<'\n';
    }
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solution();
    return 0;
}
