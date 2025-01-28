#include <bits/stdc++.h>
using namespace std;

int main()
{
    map<char,int> mp;
    mp['('] = 1;
    mp['{'] = 2;
    mp['['] = 3;
    mp['<'] = 4;
    mp[')'] = -1;
    mp['}'] = -2;
    mp[']'] = -3;
    mp['>'] = -4;
    
    
    string s;
    cin>>s;
    
    stack<char> st;
    bool is_balanced = 1;
    for(auto v:s){
        if(mp[v]>0){
            // open bracket.
            st.push(v);
        }else{
            // closing bracket
            if(st.empty()){
               is_balanced = 0; 
            }
            else if(mp[st.top()] + mp[v]==0){
                // matching brackets
                st.pop();
            }
        }
    }
    if(is_balanced && st.empty()){
        cout<<"Balanced\n";
    }else{
        cout<<"Not balanced\n";
    }

    return 0;
}