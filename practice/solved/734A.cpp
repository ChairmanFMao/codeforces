#include <bits/stdc++.h>
using namespace std;

int main(void) {
    int n;
    cin >> n;
    string s;
    cin >> s;
    int a = 0, d = 0;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == 'A')
            a++;
        else
            d++;
    }
    string out = a == d ? "Friendship" : a > d ? "Anton" : "Danik";
    cout << out << endl;
}