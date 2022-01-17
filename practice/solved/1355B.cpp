#include <bits/stdc++.h>
using namespace std;
#define ll long long

// Accepted first try!

void solve() {
    int n;
    cin >> n;
    map<int,int> numbers;
    int biggest = 0;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        numbers[a]++;
        biggest = max(biggest, a);
    }    
    int groups = 0, overflow = 0;
    for (int i = 1; i <= biggest; i++) {
        groups += (numbers[i] + overflow) / i;
        overflow = (numbers[i] + overflow) % i;
    }
    cout << groups << "\n";
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