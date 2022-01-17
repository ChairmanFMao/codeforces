#include <bits/stdc++.h>
using namespace std;
#define ll long long

// Accepted first try!
// Very happy that I put the bitwise operators and __builtin_popcount() to use.

void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    int players[m+1];
    for (int i = 0; i < m+1; i++)
        cin >> players[i];
    
    int friends = 0;
    for (int i = 0; i < m; i++) {
        // Using bitwise xor to create an int with all the bits that differ between the numbers
        int current = players[i] ^ players[m];
        // Then using __builtin_popcount() to count the number of bits in the number to see if it is less than or equal to k
        if (__builtin_popcount(current) <= k)
            friends++;
    }
    cout << friends << "\n";
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    solve();
}