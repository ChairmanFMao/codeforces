#include <iostream>
#include <cmath>
using namespace std;

// Had to look at the solution

int main(void) {
    int n, a, b, pos = 0;
    cin >> n >> a >> b;
    pos = n - max(a + 1, n - b) + 1;
    cout << pos << "\n";
    return 0;
}
