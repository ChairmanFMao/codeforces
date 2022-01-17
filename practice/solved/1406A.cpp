#include <bits/stdc++.h>
using namespace std;

// Did it first try :)

void solve() {
    int n;
    cin >> n;
    vector<int> numbers;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        numbers.push_back(a);
    }
    sort(numbers.begin(), numbers.end());
    set<int> a, b;
    for (int i = 0; i < n; i++) {
        if (a.count(numbers[i]) == 0)
            a.insert(numbers[i]);
        else if (a.count(numbers[i]) == 1 && b.count(numbers[i]) == 0)
            b.insert(numbers[i]);
    }
    int count = 0;
    bool agood = 1, bgood = 1;
    for (int i = 0; i <= 100; i++) {
        if (a.count(i) == 0)
            agood = 0;
        if (b.count(i) == 0)
            bgood = 0;
        if (agood && a.count(i))
            count++;
        if (bgood && b.count(i))
            count++;
    }
    cout << count << "\n";
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