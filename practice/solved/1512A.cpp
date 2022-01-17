#include <iostream>
#include <set>
using namespace std;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        int n;
        cin >> n;
        int a1, a2, a3, normal;
        cin >> a1 >> a2 >> a3;
        if (a1 == a2 && a2 == a3) {
            normal = a1;
        } else if (a1 == a2 && a2 != a3) {
            cout << 3 << "\n";
            normal = a1;
        } else if (a1 == a3 && a1 != a2) {
            cout << 2 << "\n";
            normal = a1;
        } else if (a2 == a3 && a1 != a2) {
            cout << 1 << "\n";
            normal = a2;
        }
        for (int j = 3; j < n; j++) {
            int a;
            cin >> a;
            if (a != normal)
                cout << j+1 << "\n";
        }
    }
}