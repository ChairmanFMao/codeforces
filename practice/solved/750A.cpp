#include <bits/stdc++.h>
using namespace std;

int main(void) {
    int n, k;
    cin >> n >> k;
    int mins = 240 - k;
    int i = 1, solved = 0;
    while (mins >= 0) {
        mins -= 5 * i;
        solved++;
        i++;
    }
    solved--;
    if (solved > n) {
        solved = n;
    }
    cout << solved << endl;
}