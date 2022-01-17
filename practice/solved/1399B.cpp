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
        int candy[n], oranges[n];
        int minCandy = 1000000000, minOranges = 1000000000;
        for (int j = 0; j < n; j++) {
            cin >> candy[j];
            if (candy[j] < minCandy)
                minCandy = candy[j];
        }
        for (int j = 0; j < n; j++) {
            cin >> oranges[j];
            if (oranges[j] < minOranges)
                minOranges = oranges[j];
        }
        long long moves = 0;
        for (int j = 0; j < n; j++) {
            if (oranges[j] > minOranges && candy[j] > minCandy) {
                int takeaway = min(oranges[j] - minOranges, candy[j] - minCandy);
                oranges[j] -= takeaway;
                candy[j] -= takeaway;
                moves += takeaway;
            }
            if (oranges[j] > minOranges)
                moves += oranges[j] - minOranges;
            if (candy[j] > minCandy)
                moves += candy[j] - minCandy;
        }
        cout << moves << "\n";
    }
}