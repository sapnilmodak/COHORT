/*
find number of total distinct subsequences of a string
*/
#include <bits/stdc++.h>
using namespace std;
int n;
string s;


int main() {
    cin>>s;
    n = s.size()-1;
    int prefix[1001];
    int lastt[1001];
    int dp[1001];
    memset(lastt , -1 , sizeof(lastt));
    dp[0] =1;
    prefix[0] =1;
    for(int i=1; i<=n; i++){
        dp[i] = prefix[i-1];
        if(lastt[s[i-1] - 'a']){
            int indu = lastt[s[i-1] - 'a'];
            dp[i] -= prefix[indu];
        }
        lastt[s[i-1] - 'a'] = i-1;
        prefix[i] = prefix[i-1] + dp[i];
    }
    cout<<prefix[n]-1<<'\n';
}
