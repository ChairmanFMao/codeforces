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
        string extra = " ";
        for (int j = 1; j < n + 1; j++) {
            if (j == n)
                extra = "\n";
            cout << j%n+1 << extra;
        }
    }
}