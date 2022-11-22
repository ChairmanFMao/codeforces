#include <bits/stdc++.h>
using namespace std;

// When looking back over this was 1700 difficulty
// This is the "hardest" problem that I have solved yet on codeforces!

int primeFactors(int number) {
    int factors = 0;
    while (number % 2 == 0) {
        number /= 2;
        factors++;
    }
    for (int i = 3; i <= number && i <= 31623; i+=2) {
        if (number % i == 0) {
            number /= i;
            factors++;
            i-=2;
        }
    }
    // This allowed time limit to be passed on test 3
    // It assumes all odds with factors over 31623(root of 1e9) are prime
    // Epicly worked :)
    if (number > 1)
        factors++;
    return factors;
}

void solve() {
    int a, b, k;
    cin >> a >> b >> k;
    int factors = primeFactors(a) + primeFactors(b);
    string out = factors >= k ? "YES" : "NO";
    if (k == 1)
        out = max(a,b)/min(a,b) > 1 && max(a,b) % min(a,b) == 0 ? "YES" : "NO";
    cout << out << "\n";
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