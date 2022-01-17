#include <bits/stdc++.h>
using namespace std;
#define ll long long

// Failed first try, WA test 3, due to the edge case of the number 1
// Failed second try, WA test 4
// Failed third try, forgot to add 2 to return true from the prime function
// Accepted third try!
// Accepted fourth try when I made a map for numbers that have been tested before to save time checking if they are prime again

map<ll, int> tested;

bool prime(ll number) {
    if (number == 2 || tested[number] == 1)
        return true;
    if (!(number & 1) || number == 1 || tested[number] == -1)
        return false;
    for (int i = 3; i <= pow(number,0.5); i+=2)
        if (number % i == 0) {
            tested[number] = -1;
            return false;
        }
    tested[number] = 1;
    return true;
}

void solve() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        ll a;
        cin >> a;
        double root = pow(a,0.5);
        if (abs((ll) root - root) < 1e-9 && prime((ll) root))
            cout << "YES" << "\n";
        else
            cout << "NO" << "\n";
    }
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    solve();
}