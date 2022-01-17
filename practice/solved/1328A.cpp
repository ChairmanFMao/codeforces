#include <bits/stdc++.h>
using namespace std;

int main(void) {
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        int a, b;
        cin >> a >> b;
        int mod = b - (a % b);
        if (a % b == 0)
            mod = 0;
        cout << mod << endl;
    }
}