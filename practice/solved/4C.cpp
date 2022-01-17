#include <bits/stdc++.h>
using namespace std;
#define ll long long

// Accepted first try!

void solve() {
    int n;
    cin >> n;
    string users[n];
    for (int i = 0; i < n; i++)
        cin >> users[i];
    
    map<string,int> currentUsers;
    for (int i = 0; i < n; i++) {
        if (currentUsers[users[i]] == 0)
            cout << "OK" << "\n";
        else
            cout << users[i] << to_string(currentUsers[users[i]]) << "\n";
        currentUsers[users[i]]++;
    }
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    solve();
}