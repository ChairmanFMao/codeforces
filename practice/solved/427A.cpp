#include <bits/stdc++.h>
using namespace std;

int main(void) {
    int n;
    cin >> n;
    int officers = 0, untreated = 0;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        if (a > 0) {
            officers += a;
        }
        else {
            if (officers > 0)
                officers--;
            else
                untreated++;
        }
    }
    cout << untreated << "\n";
}