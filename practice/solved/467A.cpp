#include <bits/stdc++.h>
using namespace std;

int main(void) {
    int n;
    cin >> n;
    int rooms = 0;
    for (int i = 0; i < n; i++) {
        int p, q;
        cin >> p >> q;
        if (q - p >= 2)
            rooms++;
    }
    cout << rooms << endl;
}