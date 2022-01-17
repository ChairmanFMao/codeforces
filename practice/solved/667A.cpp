#include <bits/stdc++.h>
using namespace std;

int main(void) {
    int n, h;
    cin >> n >> h;
    int width = 0;
    for (int i = 0; i < n; i++) {
        int height;
        cin >> height;
        width += height > h ? 2 : 1;
    }
    cout << width << endl;
}