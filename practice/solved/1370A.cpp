#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

// Looked at tutorial after O(n^2) algorithm timed out
// Think about the maths of it, just divide the number by 2 in integer division, constant time ;-;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        int n;
        cin >> n;
        int gcdNumber = n/2;
        cout << gcdNumber << "\n";
    }
}