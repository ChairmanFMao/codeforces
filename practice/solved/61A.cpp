#include <bits/stdc++.h>
using namespace std;

int main(void) {
    string a, b;
    cin >> a >> b;
    string out = "";
    for (int i = 0; i < a.length(); i++) {
        int c = a[i] - 48, d = b[i] - 48;
        out += c ^ d ? "1" : "0";
    }
    cout << out << endl;
}