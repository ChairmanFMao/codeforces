#include <bits/stdc++.h>
using namespace std;
#define ll long long

// Failed first try, WA test 5, needed to account for a specific case I didn't think of
// Accepted second try!

void solve() {
    int n;
    string a, b;
    cin >> n >> a >> b;

    int cost = 0;
    for (int i = 0; i < a.size(); i++) {
        if (a[i] == b[i])
            continue;
        if (i == a.size()-1) {
            cost++;
            continue;
        }
        if (a[i] != b[i] && a[i+1] != b[i+1] && a[i] != a[i+1]) {
            cost++;
            i++;
        } else
            cost++;
    }
    
    cout << cost << "\n";
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    solve();
}