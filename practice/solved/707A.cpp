#include <iostream>
using namespace std;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    bool bw = 1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            char a;
            cin >> a;
            if (a == 'C' || a == 'M' || a == 'Y')
                bw = 0;
        }
    }
    string out = bw ? "#Black&White" : "#Color";
    cout << out;
}