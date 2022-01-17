#include <iostream>
#include <vector>
using namespace std;

// Read the question properly, the numbers were not allowed to be reordered ;-;
int main(void) {
    int output = 0; // Remember to instantiate variables otherwise they will have a garbage value!
    int n[3];
    for (int i = 0; i < 3; i++) cin >> n[i];
    vector<int> outcomes;
    outcomes.push_back(n[0] * n[1] * n[2]);
    outcomes.push_back((n[0] + n[1]) * n[2]);
    outcomes.push_back(n[0] * (n[1] + n[2]));
    outcomes.push_back(n[0] + n[1] + n[2]);
    for (int i = 0; i < outcomes.size(); i++) if (outcomes[i] > output) output = outcomes[i];
    cout << output << endl;
    return 0;
}