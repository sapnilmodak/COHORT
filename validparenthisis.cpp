#include<bits/stdc++.h>
using namespace std;


int main()
{
    string s;
    cin>>s;
    int n = s.length();
    // build depth
    int d = 0;
    vector<int> depth;
    depth.push_back(d);
    for(auto v:s){
        if(v=='('){
            d++;
        }else{
            d--;
        }
        depth.push_back(d);
    }
    n++;
    // build the map
    map<int,vector<int>> valpos;
    for(int i=0;i<n;i++){
        valpos[depth[i]].push_back(i);
    }
    // previous smaller
    int ps[n];
    for(int i=0;i<n;i++){
        ps[i] = i-1;
        while(ps[i]!=-1 && depth[ps[i]]>=depth[i]){
            ps[i] = ps[ps[i]];
        }
    }
    // calulate answer
int ans = 0;
    for(int i=0;i<n;i++){
        int l = ps[i]+1;
        int r = i-1;
        int x = depth[i];
        if(l>r)continue;
        int lessthaneqR = upper_bound(valpos[x].begin(),valpos[x].end(),r)-valpos[x].begin();
        int lessthanL = lower_bound(valpos[x].begin(),valpos[x].end(),l)-valpos[x].begin();
        ans += lessthaneqR - lessthanL; // [l,r]
    }
    cout<<ans<<endl;
}