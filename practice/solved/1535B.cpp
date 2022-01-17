#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    // We need to sort the inputs with numbers divisible by 2 first, then the rest of the numbers with both sections in decreasing order.
    // This is done by adding inputs to different vectors, sorting the vectors and then concatenating the vectors again.
    vector<int> two, other;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        if (a % 2 == 0)
            two.push_back(a);
        else
            other.push_back(a);
    }
    sort(two.rbegin(), two.rend());
    sort(other.rbegin(), other.rend());
    // This is a way of concatenating two vectors, insert the second at the end of the first
    // With this implementation instead of my own managed to shave off 15ms on execution
    two.insert(two.end(), other.begin(), other.end());
    int good = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (__gcd(two[i], 2 * two[j]) > 1)
                good++;
        }
    }
    cout << good << "\n";
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