#include <bits/stdc++.h>
using namespace std;
#define ll long long

// What if there is a vector for each point and there is vector of pairs for the number of removals

const int mxN = 500;
// The first element contains the time, second is the removals
vector<vector<pair<ll,ll>>> dp(mxN+1);

void solve() {
    int n, l, k;
    cin >> n >> l >> k;
    int coords[n], limit[n];
    for (int i = 0; i < n; i++)
        cin >> coords[i];
    for (int i = 0; i < n; i++)
        cin >> limit[i];
    
    // Somehow you use dynamic programming to do this, unsure exactly how to apply it
    dp[1].push_back({limit[0]*coords[0],0});
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < (int) dp[i].size(); j++) {
            if (dp[i][j].second < k)
                dp[i+1].push_back({dp[i][j].first + (coords[i]-coords[i-1])*limit[i-1], dp[i][j].second + 1});
            dp[i+1].push_back({dp[i][j].first + (coords[i]-coords[i-1])*limit[i], dp[i][j].second});
        }
    }

    ll out = 1e9;
    for (int i = 0; i < (int) dp[n].size(); i++)
        out = min(out, dp[n][i].first);
    cout << out << "\n";
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    solve();
}
