#include <iostream>
using namespace std;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        int w, h ,n;
        cin >> w >> h >> n;
        int pieces = 1;
        while (w % 2 == 0 || h % 2 == 0) {
            if (w % 2 == 0) {
                pieces *= 2;
                w /= 2;
            } if (h % 2 == 0) {
                pieces *= 2;
                h /= 2;
            }
        }
        string out = pieces >= n ? "YES" : "NO";
        cout << out << "\n";
    }
}