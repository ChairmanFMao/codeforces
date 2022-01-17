#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a;
    // localMax just takes care of the array x
    int localMax = 0;
    for (int i = 0; i < n; i++) {
        int b;
        cin >> b;
        // We add the localMax because that would be equivalent number that would correspond to b in the array x that was taken away in the creation of b
        a.push_back(b + localMax);
        // This just prevents negative numbers from being added to localMax
        if (b > 0)
            localMax += b;
    }
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cout << "\n";
    solve();
}