
#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve() {
    int n;
    cin >> n;
    vector<int> numbers(n);
    for (int i = 1; i <= n; i++)
        numbers[n-i] = i;

    for (int i = 0; i < n-3; i++) {
        if (numbers[i] == 5)
            continue;
        swap(numbers[i],numbers[n-1]);
        for (int j : numbers)
            cout << j << " ";
        cout << "\n";
        swap(numbers[i],numbers[n-1]);
    }

    for (int i : numbers)
        cout << i << " ";
    cout << "\n";
    swap(numbers[n-2],numbers[n-1]);
    for (int i : numbers)
        cout << i << " ";
    cout << "\n";
    swap(numbers[n-2],numbers[n-1]);
    swap(numbers[n-3],numbers[n-2]);
    for (int i : numbers)
        cout << i << " ";
    cout << "\n";
    if (n >= 5) {
        swap(numbers[n-3],numbers[n-1]);
        for (int i : numbers)
            cout << i << " ";
        cout << "\n";
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
