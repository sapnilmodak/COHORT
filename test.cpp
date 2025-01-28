#include<bits/stdc++.h>
using namespace std;
int main(){
    map<char,int> mp;
    mp['('] = +1;
    mp['['] = +1;
    mp['{'] = +1;
    mp[')'] = +1;
    mp[']'] = +1;
    mp['}'] = +1;
    string s;
    cin>>s;
    bool is_balance = 1;
    stack<char> st;
    for(auto v:s){
        if( mp[v] > 0){
            st.push(v);
        }
        else{
            if(st.empty()){
                is_balance = 0;
                break;
            }
            else if(mp[st.top()] + mp[v] == 0){
                st.pop();
            }
        }
    }
    if(is_balance){
        cout<<"its balance";
    }
    else{
        cout<<"its not";
    }
}