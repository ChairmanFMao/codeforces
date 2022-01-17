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
        int sum = 0, two = 0;
        bool one = 0;
        for (int j = 0; j < n; j++) {
            int a;
            cin >> a;
            sum += a;
            if (a == 1)
                one = 1;
            if (a == 2)
                two++;
        }
        string out = "NO";
        if (sum % 2 == 0) {
            if (!one && two % 2 == 0)
                out = "YES";
            else if (one)
                out = "YES";
            else
                out = "NO";
        }
        cout << out << "\n";
    }
}