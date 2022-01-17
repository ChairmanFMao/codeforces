#include <bits/stdc++.h>
using namespace std;
#define ll long long

// Looking at the situation I think an O(n) or O(n logn) solution is needed
// Accepted first try and I made a O(n) algorithm :)))))

void solve() {
    int n, m;
    cin >> n >> m;
    int numbers[n];
    for (int i = 0; i < n; i++)
        cin >> numbers[i];
    
    set<int> distinct;
    int sumValues[n];
    for (int i = n-1; i >= 0; i--) {
        distinct.insert(numbers[i]);
        sumValues[i] = distinct.size();
    }

    for (int i = 0; i < m; i++) {
        int a;
        cin >> a;
        cout << sumValues[a-1] << "\n";
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    solve();
}