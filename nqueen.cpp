#include <bits/stdc++.h>
using namespace std;

void Nqueen(int col, vector<vector<string>> &ans, vector<string> &board, vector<int> &leftrow, vector<int> &upperdiag, vector<int> &lowerdiag, int n) {
    if (col == n) {
        ans.push_back(board); // Store the valid board configuration in ans
        return;
    }
    for (int row = 0; row < n; row++) {
        if (leftrow[row] == 0 && upperdiag[n - 1 + col - row] == 0 && lowerdiag[row + col] == 0) {
            board[row][col] = 'Q';
            leftrow[row] = 1;
            lowerdiag[row + col] = 1;
            upperdiag[n - 1 + col - row] = 1;
            Nqueen(col + 1, ans, board, leftrow, upperdiag, lowerdiag, n);
            board[row][col] = '.';
            leftrow[row] = 0;
            lowerdiag[row + col] = 0;
            upperdiag[n - 1 + col - row] = 0;
        }
    }
}

int main() {
    int n;
    cin >> n;
    vector<vector<string>> ans;
    vector<string> board(n, string(n, '.'));
    vector<int> leftrow(n, 0);
    vector<int> upperdiag(2 * n - 1, 0);
    vector<int> lowerdiag(2 * n - 1, 0);
    Nqueen(0, ans, board, leftrow, upperdiag, lowerdiag, n);

    // Print all the solutions
    for (const auto &solution : ans) {
        for (const string &row : solution) {
            cout << row << '\n';
        }
        cout << '\n';
    }
    return 0;}
