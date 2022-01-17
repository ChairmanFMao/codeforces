#include <bits/stdc++.h>
using namespace std;
#define ll long long

// You are trying to map string a onto string b, with a bit inverse and reversal of a substring of a.
// The length of both string a and b is n
// The substring has to be a prefix of a
// Need to output the number of transformations needed max is 3n and the length of all the substrings you transform
// Epicly accepted first try! Very pleased that I managed to think up the algorithm

void solve() {
    int n;
    string a, b;
    cin >> n >> a >> b;

    vector<int> lengths;

    for (int i = n-1; i >= 0; i--) {
        if (a[i] == b[i])
            continue;
        lengths.push_back(i+1);
        lengths.push_back(1);
        lengths.push_back(i+1);
    }

    cout << lengths.size() << " ";
    for (int i = 0; i < lengths.size(); i++)
        cout << lengths[i] << " ";
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