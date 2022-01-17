#include <iostream>
#include <vector>
using namespace std;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cout << "\n";
    int n;
    cin >> n;
    int height = 0, sum = 0;
    for (int i = 1; n > 0; i++) {
        sum += i;
        n -= sum;
        height++;
    }
    if (n != 0)
        height--;
    cout << height;
}