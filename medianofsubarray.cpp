// Given an array of N integers A. The score of a subarray is the sum of all integers in the subarray. Mr.X calculated the score of all N*(N+1))/2 subarray. Mr.X wants you to find the median of the array containing the score of all the subarray.

 

// Note: The median of a sequence is the value that is in the middle when the sequence is sorted. If the length of the sequence is even, there are two values in the middle and the median is the smaller of these values (or either when they are equal).

#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
int mod = 1e9 + 7;

bool check(int x, vector<int> arr , int n , int k){
     int sum=0;
    int tail = 0;
    int head =-1;
    int cnt=0;
    while(tail < n){
       
        while( head +1 <n && (sum + arr[head+1] <= x )){
            head++;
            sum += arr[head];
        }
        if(sum  <= x){
            cnt += (head - tail +1);
        }
        // cout<<x<<" ";
        // cout<<head<<" "<<tail<<" "<<sum<<" "<<cnt<<  '\n';
        if(tail > head){
            tail++;
            head = tail-1;
        }
        else{
            sum -= arr[tail];
            tail++;
        }
         
        
    }
    // cout<<'\n';
    return cnt>=k;
}
int bs(int lo , int hi , int s, vector<int>arr , int n){
    int ans;
      while(lo <= hi){
            int mid = (lo + hi)/2;
            if(check(mid ,arr , n , s)){
                hi = mid -1;
                ans = mid;
                // cout<<"yu";
            }
            else{
                lo = mid+1;
                // cout<<"no";
            }
            
        }
    return ans;
}
void solution() {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int lo=1e8;
        int hi=0;
        std::vector<int>arr(n);
        for(int i=0; i<n; i++){
            cin>>arr[i];
            lo = min(lo , arr[i]);
            hi += arr[i];
        }
        int s;
        int s2;
        int k= (n * (n+1))/2;
        if(k%2 ==1){
            s = (k/2)+1;
        }
        else{
            s = (k/2)+1;
            
            s2 =(k/2);
        }
        sort(arr.begin() , arr.end());
        int ans1 = bs(lo , hi , s , arr , n);
        int ans2= 1e8;
        if(k%2 == 0){
            ans2 = bs(lo , hi , s2 , arr , n);
            int ans3 = bs(lo , hi , s2-1 , arr , n);
            // if(ans1 == ans2){
            //     cout<<ans2<<'\n';
            // }
            // else{
            //     cout<<ans3<<'\n';
            // }
        }
        cout<<min(ans2 , ans1)<<'\n';
    }
    
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solution();
    return 0;
}
