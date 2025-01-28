#include <bits/stdc++.h>
using namespace std;

bool comp(pair<int, int>& a, pair<int, int>& b) {
    return (double)a.first / a.second > (double)b.first / b.second;
}

int main() {
    int n;
    cin >> n;
    int wt;
    cin >> wt;
    vector<pair<int, int>> arr(n); // Each pair contains (value, weight)
    
    for (int i = 0; i < n; i++) {
        cin >> arr[i].first >> arr[i].second;
    }
    
    // Sort items by descending value-to-weight ratio
    sort(arr.begin(), arr.end(), comp);
    
    // Display sorted items for verification
    for (auto& p : arr) {
        cout << "(" << p.first << ", " << p.second << ") ";
    }
    cout << endl;
    
    // Greedy calculation for the fractional knapsack
    double totalval = 0.0;
    for (int i = 0; i < n; i++) {
        if (arr[i].second <= wt) {
            totalval += arr[i].first;
            wt -= arr[i].second;
        } else {
            totalval += ((double)arr[i].first / arr[i].second) * wt;
            break;
        }
    }
    
    cout << totalval << '\n';
    return 0;
}
