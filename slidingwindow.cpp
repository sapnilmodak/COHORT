/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n,k;
    cin>>n>>k;
    std::vector<int>arr(n) ;
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    multiset<int> mt;
    for(int i=0; i<n; i++){
        mt.insert(arr[i]);
        if(mt.size() > k ){
            mt.erase(mt.find(arr[i-k]));
        }
        if(mt.size() == k){
            cout<<*mt.begin()<<" ";
        }
    }

    return 0;
}