#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve() {
    int n;
    cin >> n;

    set<int> numbers;
    for (int i = 1; i*i <= n; i++)
        numbers.insert(i*i);
    for (int i = 1; i*i*i <= n; i++)
        numbers.insert(i*i*i);

    cout << numbers.size() << "\n";
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