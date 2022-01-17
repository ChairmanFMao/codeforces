#include <bits/stdc++.h>
using namespace std;

int main(void) {
    int a, b;
    cin >> a >> b;
    int counter = 0;
    while (a <= b) {
        a *= 3;
        b *= 2;
        counter++;
    }
    cout << counter << endl;
}