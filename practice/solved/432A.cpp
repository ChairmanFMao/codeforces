#include <bits/stdc++.h>
using namespace std;

int main(void) {
    int n, k;
    cin >> n >> k;
    int valid = 0;
    for (int i = 0; i < n; i++) {
        int y;
        cin >> y;
        if (y + k <= 5)
            valid++;
    }
    cout << valid/3 << "\n";
}