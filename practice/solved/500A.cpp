#include <iostream>
#include <vector>
using namespace std;

int main(void) {
    int n, t;
    cin >> n >> t;
    vector<int> portals;
    for (int i = 0; i < n - 1; i++) {
        int a;
        cin >> a;
        portals.push_back(a);
    }
    for (int i = 0; true; i += portals[i]) {
        if (i + 1 == t) {
            cout << "YES" << endl;
            return 0;
        }
        // We need to have this here so that we can check i+1 against t when i >= portals.size() once before breaking out of the loop
        if (i >= portals.size()) break;
    }
    cout << "NO" << endl;
    return 0;
}