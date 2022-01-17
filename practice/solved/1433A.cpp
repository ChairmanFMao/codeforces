#include <iostream>
using namespace std;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        string x;
        cin >> x;
        int number = x[0] - 48;
        int length = x.length();
        int out = ((number - 1) * 10) + (length == 1 ? 1 : length == 2 ? 3 : length == 3 ? 6 : 10);
        cout << out << "\n";
    }
}