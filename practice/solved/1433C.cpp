#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    int biggest = 0;
    vector<int> fish, bi;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        if (a > biggest) {
            biggest = a;
            bi.clear();
            bi.push_back(i);
        } else if (a == biggest) {
            bi.push_back(i);
        }
        fish.push_back(a);
    }
    if (bi.size() == n) {
        cout << -1 << "\n";
        return;
    }
    for (int i = 0; i < bi.size(); i++) {
        if (bi[i] == 0) {
            if (fish[bi[i]+1] < biggest) {
                cout << bi[i]+1 << "\n";
                return;
            }
        } else if (bi[i] == n-1) {
            if (fish[bi[i]-1] < biggest) {
                cout << bi[i]+1 << "\n";
            }
        } else {
            if (fish[bi[i]-1] < biggest || fish[bi[i]+1] < biggest) {
                cout << bi[i]+1 << "\n";
                return;
            }
        }
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