#include <bits/stdc++.h>
using namespace std;
#define ll long long

// How to check for presence in a map
// How to use maps in general

void solve() {
    int n;
    cin >> n;
    vector<int> numbers;
    map<int, int> occur;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        // Check if map contains "a" if so update the value by adding one, otherwise add "a:1" to the map
        numbers.push_back(a);
    }
    int common = 0, repeats = 0;
    for (int i = 0; i < occur.size(); i++) {
        if (occur.second > repeats) {
            common = occur.first;
            repeats = occur.second;
        }
    }
    int remove = 0;
    for (int i = 0; i < n; i++) {
        if (numbers[i] != common)
            remove++;
    }
    cout << remove << "\n";
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