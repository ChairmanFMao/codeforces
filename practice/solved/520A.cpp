#include <bits/stdc++.h>
using namespace std;

int main(void) {
    int n;
    cin >> n;
    string s;
    cin >> s;
    bool letters[26];
    for (int i = 0; i < 26; i++)
        letters[i] = 0;
    for (int i = 0; i < s.length(); i++) {
        int a = toupper(s[i]) - 65;
        letters[a] = 1;
    }
    for (int i = 0; i < 26; i++) {
        if (letters[i] == 0) {
            cout << "NO" << endl;
            return 0;
        }
    }
    cout << "YES" << endl;
}