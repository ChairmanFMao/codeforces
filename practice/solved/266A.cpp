#include <bits/stdc++.h>
using namespace std;

int main(void) {
    int n;
    string stones;
    cin >> n >> stones;
    int remove = 0;
    for (int i = 0; i < stones.length() - 1; i++) {
        if (stones[i] == stones[i+1])
            remove++;
    }
    cout << remove << endl;
}