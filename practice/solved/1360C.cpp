#include <bits/stdc++.h>
using namespace std;
#define ll long long

// Wrong anser on test 2 on the first submission
// Failed second time due to not looking at index out of bounds
// Failed third time due to needing to make a better algorithm
// Epicly accepted on the fourth try while among us is being downloaded on my phone.

void solve() {
    int n;
    cin >> n;
    set<int> uniqueNumbers;
    map<int, int> occur;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        occur[a]++;
        uniqueNumbers.insert(a);
    }

    vector<int> numbers(uniqueNumbers.begin(), uniqueNumbers.end());
    int odd = 0, even = 0, removals = 0;
    for (int i = 0; i < numbers.size(); i++) {
        int current = occur[numbers[i]];
        if (current == 0)
            continue;
        if (i != numbers.size() - 1) {
            if (numbers[i]+1 == numbers[i+1] && (current > 0 && occur[numbers[i+1]] > 0)) {
                removals += min(current, occur[numbers[i+1]]);
                occur[numbers[i]] -= min(current, occur[numbers[i+1]]);
                occur[numbers[i+1]] -= min(current, occur[numbers[i+1]]);
            }
        }
        if (occur[numbers[i]] > 0) {
            if (numbers[i] & 1)
                odd += occur[numbers[i]];
            else
                even += occur[numbers[i]];
        }
    }
    string out = !((odd & 1) && (even & 1)) || (removals >= 1 && !(((odd+1) & 1) && ((even+1) & 1))) ? "YES" : "NO";
    cout << out << "\n";
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cout << "\n";
    int t;
    cin >> t;
    for (int i = 1; i <= t; i++)
        solve();
}