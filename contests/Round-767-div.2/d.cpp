#include <bits/stdc++.h>
using namespace std;
#define ll long long

// WA on pretest 2 on the first submission
// Still WA on pretest 2 after some changes were made

void solve() {
    int n;
    cin >> n;
    map<string,int> have;
    vector<string> lines(n);
    for (int i = 0; i < n; i++) {
        cin >> lines[i];
        have[lines[i]]++;
    }

    bool check = 0;
    string current;
    set<string> wanted, anotherhave;
    for (int i = 0; i < n; i++) {
        have[lines[i]]--;
        if ((int)lines[i].size() == 3) {
            current = lines[i].substr(0,2);
            reverse(current.begin(),current.end());
            if (have[current])
                check = 1;
            wanted.insert(current);

            current = lines[i].substr(1,2);
            reverse(current.begin(),current.end());
            if (anotherhave.count(current))
                check = 1;
        }
        if (check || lines[i][0] == lines[i][lines[i].size()-1] || wanted.count(lines[i])) {
            cout << "YES\n";
            return;
        }
        anotherhave.insert(lines[i]);
        current = lines[i];
        reverse(current.begin(),current.end());
        wanted.insert(current);
    }
    
    cout << "NO\n";
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

