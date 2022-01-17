#include <bits/stdc++.h>
using namespace std;
#define ll long long

// Took some debugging but, I got it to work well :)

void solve() {
    int n;
    cin >> n;
    vector<int> numbers(n);
    set<int> unique;
    map<int,vector<int>> positions;
    for (int i = 0; i < n; i++) {
        cin >> numbers[i];
        unique.insert(numbers[i]);
        positions[numbers[i]].push_back(i);
    }

    // Detects if there are no duplicates
    if ((int)unique.size() == n) {
        cout << -1 << "\n";
        return;
    }
    
    int out = 0, length;
    // There must be a pair for this to occur, we are trying to find the pair closest to the middle
    vector<int> pairs(unique.begin(),unique.end());
    for (int i = 0; i < (int) pairs.size(); i++) {
        length = positions[pairs[i]].size();
        if (positions[pairs[i]].size() < 2)
            continue;
        
        for (int j = 0; j < length-1; j++)
            if (positions[pairs[i]][j] + n - positions[pairs[i]][j+1] > out)
                out =  positions[pairs[i]][j] + n - positions[pairs[i]][j+1];
    }
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
