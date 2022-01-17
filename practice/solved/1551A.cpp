#include <iostream>
using namespace std;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        int n;
        cin >> n;
        int one = n/3, two = n/3;
        if (n - one - two * 2 == 1)
            one++;
        else if (n - one - two * 2)
            two++;
        cout << one << " " << two << "\n";
    }
}