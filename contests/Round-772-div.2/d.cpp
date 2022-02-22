#include <bits/stdc++.h>
using namespace std;
#define ll long long

// All multiples of 4, all odd numbers, all numbers in array
// There is no easy way to do this using numbers
// Times four is a bitshift of 2 to the left
// Times two + 1 is a bitshift of 1 to the left and just 1 at the end
// Something to do with bitwise operators
// Not sure with how to deal with one number mapping onto another
// Potentially dynamic programming
// TLE on test 5, I think that the dfs is too slow, changed to bfs and still too slow
//
// Looked at solution, you need to work backwards from the numbers, much more efficient
// Trying to find the root of the number
const ll MOD = 1e9 + 7, mxN = 2e5;
vector<ll> numbers(mxN), dp(mxN+3, 0), dpo(mxN+1);
set<ll> useful;
ll n, p, out = 0, cap = 1e9+1;

void solve() {
    cin >> n >> p;
    for (int i = 0; i < n; i++)
        cin >> numbers[i];
    
    if (p < 30)
        cap = 1 << p;
    
    sort(numbers.begin(),numbers.begin()+n);
    for (int i = 0; i < n; i++) {
        ll current = numbers[i];
        bool good = 0;
        while (current > 0) {
            if (useful.count(current)) {
                good = 1;
            } if (current & 1) {
                current >>= 1;
            } else if (current & 3) {
                break;
            } else {
                current >>= 2;
            }
        }
        if (!good && numbers[i] < cap)
            useful.insert(numbers[i]);
    }
    
    ll total = 0;
    dp[0] = 1;
    for (int i = 0; i <= p; i++) {
        dp[i+1] = (dp[i+1] + dp[i]) % MOD;
        dp[i+2] = (dp[i+2] + dp[i]) % MOD;
        total = (total + dp[i]) % MOD;
        dpo[i] = total;
    }

    vector<ll> filtered(useful.begin(),useful.end());
    for (int i = 0; i < (int)filtered.size(); i++) {
        out = (out + dpo[p-(64 - __builtin_clzll(filtered[i]))]) % MOD;
    }
    cout << out << "\n";
}

int main(void) {
    //ios::sync_with_stdio(0);
    //cin.tie(0);

    solve();
}
