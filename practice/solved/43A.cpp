#include <iostream>
#include <cstring>
using namespace std;

int main(void) {
    int n, team1 = 0, team2 = 0;
    cin >> n;
    string goals[n];
    string name = "";
    string othername = "";
    for (int i = 0; i < n; i++) {
        string a;
        cin >> a;
        if (i == 0) name = a;
        if (i > 0 && a != name) othername = a;
        if (name == a) team1++;
        else team2++;
    }
    string winner = team1 > team2 ? name : othername;
    cout << winner << endl;
    return 0;
}