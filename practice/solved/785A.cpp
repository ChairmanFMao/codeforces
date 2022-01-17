#include <bits/stdc++.h>
using namespace std;

int main(void) {
    int n;
    cin >> n;
    int sides = 0;
    for (int i = 0; i < n; i++) {
        string name;
        cin >> name;
        if (name == "Tetrahedron")
            sides += 4;
        else if (name == "Cube")
            sides += 6;
        else if (name == "Octahedron")
            sides += 8;
        else if (name == "Dodecahedron")
            sides += 12;
        else if (name == "Icosahedron")
            sides += 20;
    }
    cout << sides << endl;
}