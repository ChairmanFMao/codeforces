#include <iostream>
using namespace std;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        int n;
        cin >> n;
        int evenBad = 0, oddBad = 0;
        for (int j = 0; j < n; j++) {
            int a;
            cin >> a;
            if (a % 2 != j % 2 && j % 2 == 0)
                evenBad++;
            else if (a % 2 != j % 2 && j % 2 == 1)
                oddBad++;
        }
        if (oddBad == evenBad) {
            cout << oddBad << "\n";
        } else {
            cout << -1 << "\n";
        }
    }
}