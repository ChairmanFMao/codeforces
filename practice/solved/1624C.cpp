#include <bits/stdc++.h>
using namespace std;
#define ll long long

const int mxN = 50;
vector<vector<int>> possible(mxN+1);

void solve() {
    int n;
    cin >> n;
    int numbers[n];
    for (int i = 0; i < n; i++) {
        cin >> numbers[i];
        possible[i+1].clear();
    }
    
    // Just need to check if numbers from 1 to n can be generated from array
    // Unsure how to approach this problem
    for (int i = 0, copy; i < n; i++) {
        copy = numbers[i];
        while (copy) {
            if (copy <= 50)
                possible[copy].push_back(numbers[i]);
            copy /= 2;
        }
    }

    for (int i = n; i > 0; i--) {
        if (!possible[i].size()) {
            cout << "NO\n";
            return;
        }
        int removing = possible[i][0];
        for (int j = n; j > 0; j--) {
            for (int k = 0; k < (int)possible[j].size(); k++)
                if (possible[j][k] == removing) {
                    possible[j].erase(possible[j].begin()+k);
                    break;
                }
        }
    }
    cout << "YES\n";
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
