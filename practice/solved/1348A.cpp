#include <iostream>
#include <cmath>
using namespace std;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        int n;
        cin >> n;
        int a = pow(2,n);
        for (int j = 1; j < n/2; j++) {
            a += pow(2,j);
        }
        for (int j = n/2; j < n; j++) {
            a -= pow(2,j);
        }
        cout << abs(a) << "\n";
    }
}