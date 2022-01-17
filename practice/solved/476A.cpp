#include <iostream>
#include <cmath>
using namespace std;

int main(void) {
    int n, m;
    cin >> n >> m;
    if (m > n) {
        cout << -1 << "\n";
        return 0;
    }
    int number = round((float) n / 2);
    while (number % m != 0) number++;
    cout << number << "\n";
    return 0;
}