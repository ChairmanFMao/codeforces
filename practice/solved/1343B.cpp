#include <bits/stdc++.h>
using namespace std;

int main(void) {
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        int n;
        cin >> n;
        if (n % 4 != 0) {
            cout << "NO" << "\n";
            continue;
        }
        cout << "YES" << "\n";
        int evenSum = 0;
        for (int j = 2; j <= n; j+=2) {
            cout << j << " ";
            evenSum += j;
        }
        int oddSum = 0;
        for (int j = 1; j < n-2; j+=2) {
            cout << j << " ";
            oddSum += j; 
        }
        cout << evenSum - oddSum << "\n";
    }
}