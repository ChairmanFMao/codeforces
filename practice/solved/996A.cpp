#include <bits/stdc++.h>
using namespace std;

int main(void) {
    int n;
    cin >> n;
    int bills = 0;
    while (n != 0) {
        n -= n >= 100 ? 100 : n >= 20 ? 20 : n >= 10 ? 10 : n >= 5 ? 5 : 1;
        bills++;
    }
    cout << bills << endl;
}