#include <bits/stdc++.h>
using namespace std;
#define ll long long

// Failed first try, WA test 4, just some edge case that wasn't accounted for
// Failed second try, WA test 3, fixing one edge case screwed up another
// Accepted third try!

void solve() {
    int n, k;
    cin >> n >> k;
    int numbers[n];
    set<int> unique;
    map<int,int> occur;
    for (int i = 0; i < n; i++) {
        cin >> numbers[i];
        unique.insert(numbers[i]);
        occur[numbers[i]]++;
    }
    
    if (k == 0) {
        int out = *min_element(numbers,numbers+n)-1;
        string word = out >= 1 ? to_string(out) : "-1";
        cout << word << "\n";
        return;
    }
    vector<int> vectorUnique(unique.begin(), unique.end());
    int less = 0;
    for (int i = 0; i < vectorUnique.size() && less <= k; i++) {
        less += occur[vectorUnique[i]];
        if (less == k) {
            cout << vectorUnique[i] << "\n";
            return;
        }
    }
    cout << -1 << "\n";
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    solve();
}