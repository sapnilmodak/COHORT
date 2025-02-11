#include <iostream>
#include <vector>
using namespace std;

string longestPalindromicSubstring(string s) {
    // Transform the string to handle even-length palindromes
    string T = "#";
    for (char c : s) {
        T += c;
        T += "#";
    }
    
    int n = T.size();
    vector<int> P(n, 0);  // Array to store palindrome lengths
    int C = 0, R = 0;     // Center and right boundary of the current palindrome
    
    int maxLen = 0, centerIndex = 0;
    
    for (int i = 1; i < n - 1; i++) {
        int mirror = 2 * C - i;  // Mirror index of i around center C
        
        if (i < R)
            P[i] = min(R - i, P[mirror]);

        // Expand around center i
        while (i + P[i] + 1 < n && i - P[i] - 1 >= 0 && T[i + P[i] + 1] == T[i - P[i] - 1]) {
            P[i]++;
        }

        // Update center and right boundary
        if (i + P[i] > R) {
            C = i;
            R = i + P[i];
        }

        // Update max palindrome length
        if (P[i] > maxLen) {
            maxLen = P[i];
            centerIndex = i;
        }
    }

    // Extract the longest palindrome
    int start = (centerIndex - maxLen) / 2;
    return s.substr(start, maxLen);
}

int main() {
    string s = "babad";
    cout << "Longest Palindromic Substring: " << longestPalindromicSubstring(s) << endl;
    return 0;
}
