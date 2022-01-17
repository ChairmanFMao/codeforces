#include <bits/stdc++.h>
using namespace std;

int main(void) {
    long long n;
    cin >> n;
    long long out = n % 2 == 0 ? n/2 : -1 * (n/2 + 1);
    cout << out << endl;
}