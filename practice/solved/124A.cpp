#include <iostream>
#include <cmath>
using namespace std;

int main(void) {
    int n, a, b;
    cin >> n >> a >> b;
    int pos = a < n - b ? n - a : n - a;
    cout << pos << "\n";
    return 0;
}