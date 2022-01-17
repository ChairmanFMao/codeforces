#include <bits/stdc++.h>
#include <set>
using namespace std;

int main(void) {
    int current[4];
    set<int> colours;
    for (int i = 0; i < 4; i++) {
        cin >> current[i];
        colours.insert(current[i]);
    }
    int out = 4 - colours.size();
    cout << out << endl;
}