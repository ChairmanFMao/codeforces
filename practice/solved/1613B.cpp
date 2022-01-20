
#include <bits/stdc++.h>
using namespace std;
#define ll long long

// The time complexity of the current solution is just O(n^2) so, I am not sure if it will timeout
// Turns out that it did timeout, I think that the O(n^2) logic is just too bad
// Ended up looking at solution, its not that difficult just needed to think about the perculiar problem constraints

void solve() {
    int n;
    cin >> n;
    vector<int> numbers(n);
    int min = 1e9, index = 0;
    for (int i = 0; i < n; i++) {
        cin >> numbers[i];
        if (numbers[i] < min) {
            min = numbers[i];
            index = i;
        }
    }
    
    int pairs = 0;
    for (int i = 0; i < n && pairs < n/2; i++) {
        if (i == index)
            continue;
        cout << numbers[i] << " " << min << "\n";
        pairs++;
    }
    
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
