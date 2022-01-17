#include <bits/stdc++.h>
using namespace std;
#define ll long long

// WA on pretest 2

void solve() {
    int n;
    cin >> n;
    set<int> unique;
    map<int,int> occurs;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        unique.insert(a);
        occurs[a]++;
    }
    
    int different = 0;
    vector<int> numbers(unique.begin(), unique.end());
    for (int i = 0; i < numbers.size(); i++) {
        if (occurs[numbers[i]] > 1 && numbers[i] != 0 && occurs[-numbers[i]] == 0)
            different += 2;
        else
            different++;
    }
    cout << different << "\n";
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