#include <bits/stdc++.h>
#include <set>
using namespace std;

int main(void) {
    string s;
    getline(cin, s);
    set<char> chars;
    for (int i = 0; i < s.length(); i++) {
        char a = s[i];
        if (isalpha(a))
            chars.insert(a);
    }
    cout << chars.size() << endl;
}