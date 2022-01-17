#include <bits/stdc++.h>
using namespace std;

int main(void) {
    int n;
    cin >> n;
    bool hard = 0;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        if (a == 1)
            hard = true;
    }
    string out = hard ? "HARD" : "EASY";
    cout << out << endl;
}