
#include <bits/stdc++.h>
using namespace std;
#define ll long long

// I think that it must be important that n is an even number, idk how tho
// Ended up looking at solution, it used a strategy that I had saw before ;-;
// It was in a previous bio paper and the problem also puzzled me then
// This solution leverages the fact that a unique top row can have the rest of the array done
// by checking if the cell above has been used, if not then it will be called, greedily.

const int mxN = 1e3;
int n;
vector<vector<int>> numbers(mxN, vector<int> (mxN));
vector<vector<int>> used(mxN, vector<int> (mxN));

void change(int y, int x) {
    if (y > 0)
        used[y-1][x] ^= 1;
    if (y < n-1)
        used[y+1][x] ^= 1;
    if (x > 0)
        used[y][x-1] ^= 1;
    if (x < n-1)
        used[y][x+1] ^= 1;
}

void solve() {
    cin >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) {
            cin >> numbers[i][j];
            used[i][j] = 0;
        }
    
    int out = 0;
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (!used[i-1][j]) {
                out ^= numbers[i][j];
                change(i,j);
            }
        }
    }

    cout << out << "\n";
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cout << "\n";
    int t;
    cin >> t;
    for (int i = 1; i <= t; ++i)
        solve();
}
