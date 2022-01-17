#include <iostream>
using namespace std;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    cout << n/2 << "\n";
    if (n % 2 == 0) {
        string end = " ";
        for (int i = 0; i < n/2; i++) {
            if (i == n/2 - 1)
                end = "";
            cout << 2 << end;
        }
    } else {
        for (int i = 0; i < n/2 - 1; i++) {
            cout << 2 << " ";
        }
        cout << 3;
    }
}