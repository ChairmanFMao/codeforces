#include <bits/stdc++.h>
using namespace std;
#define ll long long

// WA test 1, need to make better algorithm
// WA test 1 again, wasn't properly understanding what the problem was asking for
// Accepted third try!

void solve() {
    int n;
    cin >> n;
    int numbers[n];
    for (int i = 0; i < n; i++)
        cin >> numbers[i];
    string s;
    cin >> s;

    int disliked = 0;
    for (int i = 0; i < n; i++)
        if (s[i] == '0')
            disliked++;
    vector<int> bad, good;
    for (int i = 0; i < n; i++) {
        if (s[i] == '1' && numbers[i] > disliked || s[i] == '0' && numbers[i] <= disliked)
            continue;
        if (s[i] == '1')
            bad.push_back(numbers[i]);
        else
            good.push_back(numbers[i]);
    }
    sort(bad.begin(), bad.end());
    sort(good.begin(), good.end());
    int gptr = 0, bptr = 0;
    vector<int> out(n);
    for (int i = 0; i < n; i++) {
        if (s[i] == '1' && numbers[i] > disliked || s[i] == '0' && numbers[i] <= disliked)
            out[i] = numbers[i];
        else if (s[i] == '1') {
            out[i] = good[gptr];
            gptr++;
        } else {
            out[i] = bad[bptr];
            bptr++;
        }
    }
    for (int i : out)
        cout << i << " ";
    cout << "\n";
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