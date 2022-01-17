#include <bits/stdc++.h>
#include <set>
using namespace std;

int main(void) {
    int n;
    cin >> n;
    set<int> levels;
    for (int i = 0; i < 2; i++) {
        // I didn't notice that each row had seperate value of p :(
        int p;
        cin >> p;
        for (int j = 0; j < p; j++) {
            int a;
            cin >> a;
            levels.insert(a);
        }
    }
    for (int i = 1; i <= n; i++) {
        if (levels.count(i) == 0) {
            cout << "Oh, my keyboard!" << endl;
            return 0;
        }
    }
    cout << "I become the guy." << endl;
}