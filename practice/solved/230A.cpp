#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

// Custom data structure for each dragon
struct dragon {
    int power, boost;
};

// Custom compare function to sort dragons in descending power order
bool compareDragon(dragon first, dragon second) {
    return first.power < second.power;
}

int main(void) {
    int s, n;
    cin >> s >> n;
    vector<dragon> dragons;
    for (int i = 0; i < n; i++) {
        int power, boost;
        cin >> power >> boost;
        dragon newDragon;
        newDragon.power = power;
        newDragon.boost = boost;
        dragons.push_back(newDragon);
    }
    // We use the sort function from the header file bits/stdc++.h
    sort(dragons.begin(), dragons.end(), compareDragon);
    for (int i = 0; i < n; i++) {
        if (s > dragons[i].power) s += dragons[i].boost;
        else {
            cout << "NO" << endl;
            return 0;
        }
    }
    cout << "YES" << endl;
    return 0;
}