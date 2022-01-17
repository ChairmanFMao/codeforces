#include <bits/stdc++.h>
using namespace std;

int main(void) {
    int n;
    cin >> n;
    int home[n];
    int away[n];
    for (int i = 0; i < n; i++) {
        int h, a;
        cin >> h >> a;
        home[i] = h;
        away[i] = a;
    }
    int collisions = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (home[i] == away[j]) {
                collisions++;
            }
        }
    }
    cout << collisions << endl;
}