#include <bits/stdc++.h>
using namespace std;
#define ll long long

// Looked at solution because I spent a lot of time thinking about it and didn't really know what to do
// We need to look at each subsection of the array with numbers of the same sign and add the biggest one to the final subsequence
// Accepted first try!
// I get the way that the algorithm works, it really is amazing and just thinking about it reminds me of the elegance of code

void solve() {
    ll n;
    cin >> n;
    ll numbers[n];
    for (ll i = 0; i < n; i++)
        cin >> numbers[i];
    
    int ptr = 0, sign = numbers[0] > 0 ? 1 : -1;
    ll out = 0;
    vector<int> sub;
    while (ptr < n) {
        int current = numbers[ptr] > 0 ? 1 : -1;
        if (current == sign) {
            sub.push_back(numbers[ptr]);
            ptr++;
            continue;
        }
        out += *max_element(sub.begin(), sub.end());
        sign = sign == 1 ? -1 : 1;
        sub.clear();
    }
    if (sub.size() > 0)
        out += *max_element(sub.begin(), sub.end());
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