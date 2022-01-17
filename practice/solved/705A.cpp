#include <bits/stdc++.h>
using namespace std;

int main(void) {
    int n;
    cin >> n;
    string out = "";
    for (int i = 0; i < n; i++) {
        out += i % 2 == 0 ? "I hate" : "I love";
        out += i != n-1 ? " that " : " it";
    }
    cout << out << endl;
}