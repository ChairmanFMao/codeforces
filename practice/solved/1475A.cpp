#include <bits/stdc++.h>
#include <cmath>
using namespace std;

// Used logs in my solution but, there is a way to do it using the bitwise and operator
// I coded up the solution with the bitwise and in the function otherSolve

void solve() {
    long long n;
    cin >> n;
    double result = log2 (n);
    string out = abs((int) result - result) < 1e-9 ? "NO" : "YES";
    cout << out << "\n";
}

void otherSolve() {
    long long n;
    cin >> n;
    // We can use the knowledge that if a number is a power of 2 it will only have a single 1 in its binary representation
    string out = n&(n-1) ? "YES" : "NO";
    cout << out << "\n";
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cout << "\n";
    int t;
    cin >> t;
    for (int i = 1; i <= t; ++i)
        Solve();
}