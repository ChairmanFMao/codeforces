#include <bits/stdc++.h>
using namespace std;

void solve() {
    int k;
    cin >> k;
    int months[12];
    for (int i = 0; i < 12; i++)
        cin >> months[i];
    sort(months, months + 12);
    int growth = 0, counter = 0;
    for (int i = 11; i >= 0 && growth < k; i--) {
        growth += months[i];
        counter++;
    }
    int out = growth < k ? -1 : counter;
    cout << out << "\n";
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cout << "\n";
    solve();
}