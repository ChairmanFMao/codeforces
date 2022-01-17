#include <bits/stdc++.h>
using namespace std;
#define ll long long

// Epicly accepted first try!

void solve() {
    string s, t, p;
    cin >> s >> t >> p;

    // I think that I need to loop over the strings and check the number of characters present and the order of s matters
    // I don't think that brute force is a good idea as there are just too many possibilities

    // This stores the number occurances of each character in the string t
    map<char,int> tOccurs;
    for (int i = 0; i < t.size(); i++)
        tOccurs[t[i]]++;
    
    int lastIndex = -1;
    for (int i = 0; i < s.size(); i++) {
        bool found = 0;
        for (int j = lastIndex+1; j < t.size(); j++) {
            if (t[j] == s[i]) {
                found = 1;
                tOccurs[t[j]]--;
                lastIndex = j;
                break;
            }
        }
        if (!found) {
            cout << "NO" << "\n";
            return;
        }
    }

    for (int i = 0; i < p.size(); i++)
        if (tOccurs[p[i]] > 0)
            tOccurs[p[i]]--;

    int sum = 0;
    for (int i = 0; i < t.size(); i++)
        sum += tOccurs[t[i]];
    
    if (sum)
        cout << "NO" << "\n";
    else
        cout << "YES" << "\n";
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    for (int i = 1; i <= t; ++i)
        solve();
}