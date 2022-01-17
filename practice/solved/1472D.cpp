#include <bits/stdc++.h>
using namespace std;
#define ll long long

// Accepted first try! Lets go!

void solve() {
    int n;
    cin >> n;
    vector<int> even, odd;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        if (a & 1)
            odd.push_back(a);
        else
            even.push_back(a);
    }
    
    sort(even.begin(), even.end());
    sort(odd.begin(), odd.end());
    ll alice = 0, bob = 0;
    int turn = 0;
    while (even.size() > 0 || odd.size() > 0) {
        if (turn == 0) {
            if (even.size() > 0 && odd.size() > 0) {
                if (even[even.size()-1] < odd[odd.size()-1]) {
                    odd.pop_back();
                    turn = turn == 0 ? 1 : 0;
                    continue;
                }
            }
            if (even.size() > 0) {
                alice += even.back();
                even.pop_back();
            } else
                odd.pop_back();
        } else {
            if (even.size() > 0 && odd.size() > 0) {
                if (odd[odd.size()-1] < even[even.size()-1]) {
                    even.pop_back();
                    turn = turn == 0 ? 1 : 0;
                    continue;
                }
            }
            if (odd.size() > 0) {
                bob += odd.back();
                odd.pop_back();
            } else
                even.pop_back();
        }
        turn = turn == 0 ? 1 : 0;
    }
    string out = alice == bob ? "Tie" : alice > bob ? "Alice" : "Bob";
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