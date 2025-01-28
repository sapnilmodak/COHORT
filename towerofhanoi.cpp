#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
int mod = 1e9 + 7;

void tow_hanoi(int x,string a, string b , string c){
    if(x==0){
        return;
    }
    tow_hanoi(x-1 , a , c, b);
    cout<<x<<" from "<<a<<" to  "<<b<<" using "<<c<<'\n';
    tow_hanoi(x-1,c,b,a);
}

void solution() {
    int n;
    cin>>n;
    tow_hanoi(n ,"source" , "target","aux");
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solution();
    return 0;
}
