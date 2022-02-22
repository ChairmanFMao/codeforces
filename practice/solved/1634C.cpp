
#include <bits/stdc++.h>
using namespace std;
#define ll long long

// Perculiar constraints on problem, t, n and k are all maxed out at 500
// I think that the key to this will be about having odd and number numbers next to
// each other. As this cannot occur anywhere. Each row can only contain odd or even numbers.
// Unsure if I can just do this greedily to generate the grid.
// The time complexity of this is kinda bad, so it didn't manage to pass test 3
// I thought due to the constraints it would work but, oh well...
// Time complexity is roughly O(n^2 k^2 * 0.5), a bit too slow for n=500 and k=500
// It was actually much simpler than I thought, I was just being a bit silly ;-;

void solve() {
    int n, k;
    cin >> n >> k;

    // This just checks if the number of odd and even numbers can fit onto lines.
    if (((n*k+1) >> 1) % k || ((n*k) >> 1) % k) {
        cout << "NO\n";
        return;
    }
    
    cout << "YES\n";
    for (int i = 1; i <= n*k; i+=2) {
        cout << i << " ";
        if (!(((i+1) >> 1)%k))
            cout << "\n";
    }
    for (int i = 2; i <= n*k; i+=2) {
        cout << i << " ";
        if (!((i >> 1) % k))
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
