#include <iostream>
#include <cmath>
using namespace std;

int main(void) {
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        long long price = 0;
        long long a, b, x, y;
        cin >> x >> y >> a >> b;
        if (b < a * 2) {
            price += min(x,y) * b;
            price += a * (max(x,y) - min(x,y));
        } else price = a * (x + y);
        cout << price << endl;
    }
    return 0;
}