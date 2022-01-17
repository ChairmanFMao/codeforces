#include <bits/stdc++.h>
using namespace std;

int main(void) {
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        int n;
        cin >> n;
        int out;
        if (n % 2 == 0)
            out = n/2 - 1;
        else
            out = n/2;
        cout << out << endl;
    }
}