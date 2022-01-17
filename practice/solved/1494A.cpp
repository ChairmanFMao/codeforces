#include <bits/stdc++.h>
using namespace std;
#define ll long long

// Epicly accepted first try!
// Honestly I think that the algorithm is quite bad, so I'm going to look at the model solution

void solve() {
    string a;
    cin >> a;

    int aCount = 0, bCount = 0, cCount = 0;
    for (int i = 0; i < a.size(); i++) {
        if (a[i] == 'A')
            aCount++;
        else if (a[i] == 'B')
            bCount++;
        else if (a[i] == 'C')
            cCount++;
    }

    char aType = ' ', bType = ' ', cType = ' ';
    if (a[0] == a[a.size()-1]) {
        cout << "NO" << "\n";
        return;
    }
    if (a[0] == 'A')
        aType = '(';
    if (a[0] == 'B')
        bType = '(';
    if (a[0] == 'C')
        cType = '(';
    if (a[a.size()-1] == 'A')
        aType = ')';
    if (a[a.size()-1] == 'B')
        bType = ')';
    if (a[a.size()-1] == 'C')
        cType = ')';
    
    if (aType == ' ')
        aType = bCount > cCount ? cType : bType;
    if (bType == ' ')
        bType = aCount > cCount ? cType : aType;
    if (cType == ' ')
        cType = bCount > aCount ? aType : bType;
    
    int open = 0;
    char current;
    for (int i = 0; i < a.size(); i++) {
        if (a[i] == 'A')
            current = aType;
        if (a[i] == 'B')
            current = bType;
        if (a[i] == 'C')
            current = cType;
        open += current == '(' ? 1 : -1;
        if (open < 0) {
            cout << "NO" << "\n";
            return;
        }
    }
    if (open == 0)
        cout << "YES" << "\n";
    else
        cout << "NO" << "\n";
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