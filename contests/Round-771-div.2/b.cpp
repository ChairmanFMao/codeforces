
#include <bits/stdc++.h>
using namespace std;
#define ll long long

// only swap elements next to each other

void solve() {
    int n;
    cin >> n;
    vector<int> numbers(n);
    for (int& i : numbers)
        cin >> i;
    
    // Checks if initally sorted.
    vector<int> sorted = numbers;
    sort(sorted.begin(),sorted.end());
    bool good = 1;
    for (int i = 0; i < n; i++) {
        if (sorted[i] != numbers[i]) {
            good = 0;
            break;
        }
    }

    if (good) {
        cout << "YES\n";
        return;
    }
    
    bool allEven = 0;
    for (int i : numbers)
        allEven |= (i & 1);

    if (!allEven) {
        cout << "NO\n";
        return;
    }

    int largesto = 0, largeste = 0;
    for (int i = 0; i < n; i++) {
        if (numbers[i] & 1) {
            if (largesto > numbers[i]) {
                cout << "NO\n";
                return;
            } else {
                largesto = numbers[i];
            }
        } else {
            if (largeste > numbers[i]) {
                cout << "NO\n";
                return;
            } else {
                largeste = numbers[i];
            }
        }
    }
    cout << "YES\n";
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
