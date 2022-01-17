#include <bits/stdc++.h>
using namespace std;

int main(void) {
    string s, t;
    cin >> s >> t;
    reverse(s.begin(), s.end());
    string out = s == t ? "YES" : "NO";
    cout << out << endl;
}