#include <bits/stdc++.h>
using namespace std;
#define ll long long

int n;

void solve() {
    cin >> n;
    
    // The number for the biggest xor will be the biggest power of 2 in the sequence
    int pow = 1;
    while (pow < n)
        pow <<= 1;
    pow >>= 1;
    vector<int> out(n);
    int ptr = 0;
    for (int i = n-1; i >= pow; i--) {
        out[ptr] = i;
        ptr++;
    }
    out[ptr] = 0;
    ptr++;
    for (int i = 1; i < pow; i++) {
        out[ptr] = i;
        ptr++;
    }
    for (int i : out)
        cout << i << " ";
    cout << "\n";
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
