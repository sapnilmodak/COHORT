#include <bits/stdc++.h>
using namespace std;

int n,k;
vector<string> ans;

string cur;
void rec(int level, int depth, int max_depth){ // decided [level...n] with last choices leading to cur.
    if(depth<0 || max_depth>k) return;
    // base case
    if(level==n){
        if(depth==0 && max_depth==k){
            ans.push_back(cur);
        }
        return;
    }
    // recursive case
    cur+='(';
    rec(level+1, depth+1, max(max_depth,depth+1));
    cur.pop_back();
    
    
    cur+=')';
    rec(level+1, depth-1, max(max_depth,depth-1));
    cur.pop_back();
    return;
}

int main(){
    cin>>n>>k;
    rec(0,0,0);
    cout<<ans.size()<<endl;
    for(auto v:ans){
        cout<<v<<endl;
    }
}