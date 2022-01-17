#include <bits/stdc++.h>
using namespace std;

// Had to look at the tutorial, kinda dumbfounded by the problem after first attempt

int main(void) {
    int k, r;
    cin >> k >> r;
    for (int i = 1;; i++) {
         if ((k * i) % 10 == r || (k * i) % 10 == 0) {
             cout << i << "\n";
             break;
         }
    }
}