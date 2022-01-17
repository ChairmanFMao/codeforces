#include <iostream>
#include <map>
using namespace std;

int main(void) {
    int n, m;
    cin >> n >> m;
    map<string, string> map;
    for (int i = 0; i < m; i++) {
        string a, b;
        cin >> a >> b;
        map[a] = b.length() < a.length() ? b : a;
    }
    string lecture;
    for (int i = 0; i < n; i++) {
        cin >> lecture;
        cout << map[lecture] << "\n";
    }
    return 0;
}