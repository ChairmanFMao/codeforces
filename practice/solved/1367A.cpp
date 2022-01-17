#include <bits/stdc++.h>
using namespace std;

int main(void) {
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        string word;
        cin >> word;
        string out = "";
        out += word[0];
        for (int j = 1; j < word.length(); j+=2) {
            out += word[j];
        }
        cout << out << "\n";
    }
}