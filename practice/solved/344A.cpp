#include <bits/stdc++.h>
using namespace std;

int main(void) {
    int n;
    cin >> n;
    int groups = 0;
    string magnet = "";
    string last = "";
    for (int i = 0; i < n; i++) {
        last = magnet;
        cin >> magnet;
        if (last != magnet)
            groups++;
    }
    cout << groups << endl;
}