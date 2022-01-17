#include <bits/stdc++.h>
using namespace std;
#define ll long long

// Accepted after implementing a linear time algorithm
// Failed once before on pc, in Cambridge rn. It's pretty nice being with the Americans.

void solve() {
    int n;
    cin >> n;
    vector<string> names;
    names.push_back("Sheldon");
    names.push_back("Leonard");
    names.push_back("Penny");
    names.push_back("Rajesh");
    names.push_back("Howard");

    if (n <= 5) {
        cout << names[n-1] << "\n";
        return;
    }

    for (int i = 5; n > 0; i*=2) {
        if (n - i > 0) {
            n -= i;
            continue;
        }
        int counter = 0;
        for (int j = i/5; j < 2 * i; j+= i/5) {
            if (n <= j) {
                cout << names[counter] << "\n";
                return;
            }
            counter++;
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    solve();
}