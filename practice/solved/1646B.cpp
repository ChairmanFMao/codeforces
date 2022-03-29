
#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve() {
    int n;
    cin >> n;
    vector<int> numbers(n);
    for (int& i : numbers)
        cin >> i;

    sort(numbers.begin(),numbers.end());
    ll lower = numbers[0], upper = 0;

    for (int i = 0; i < (n-1)/2; i++) {
        lower += numbers[i+1];
        upper += numbers[numbers.size()-1-i];

        if (upper > lower) {
            cout << "YES\n";
            return;
        }
    }
    cout << "NO\n";
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
