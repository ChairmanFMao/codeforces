#include <bits/stdc++.h>
using namespace std;
#define ll long long

// As the cap of s is 500 characters and the cap of t is 999 characters I think that a brute force search will work fine
// Failed first try with a WA on test 2, didn't read and understand the problem properly
// Accepted second try! Need to read the problem fully and not just skip text as it effects the program a lot

string target, original;

bool check(int index, int position, bool right) {
    if (target.size() == 1)
        return 1;
    if (original[index] == target[position] && position == target.size()-1)
        return 1;
    bool out = 0;
    if (original[index] == target[position]) {
        if (index > 0 && !right)
            out |= check(index-1, position+1, 0);
        if (index < original.size()-1 && right)
            out |= check(index+1, position+1, 1);
        if (index > 0 && right)
            out |= check(index-1, position+1, 0);
    }
    return out;
}

void solve() {
    string s, t;
    cin >> s >> t;

    target = t;
    original = s;
    bool solved = 0;
    for (int i = 0; i < s.size(); i++)
        if (s[i] == t[0])
            solved |= check(i,0,1);
    
    solved ? cout << "YES\n" : cout << "NO\n";
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