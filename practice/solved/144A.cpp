#include <bits/stdc++.h>
using namespace std;

int main(void) {
    int n;
    cin >> n;
    int max = 0, min = 100, maxPos = 0, minPos = 0;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        if (a <= min) {
            min = a;
            minPos = i;
        } if (a > max) {
            max = a;
            maxPos = i;
        }
    }
    int moves = maxPos + n - minPos - 1;
    moves -= minPos < maxPos ? 1 : 0;
    cout << moves << endl;
}