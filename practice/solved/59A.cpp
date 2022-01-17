#include <bits/stdc++.h>
using namespace std;

int main(void) {
    string s;
    cin >> s;
    int upper = 0, lower = 0;
    for (int i = 0; i < s.length(); i++) {
        if (isupper(s[i]))
            upper++;
        else if (islower(s[i]))
            lower++;
    }
    bool up = upper > lower;
    for (int i = 0; i < s.length(); i++) {
        s[i] = up ? toupper(s[i]) : tolower(s[i]);
    }
    cout << s << endl;
}