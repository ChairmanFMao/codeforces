#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

// Did read the tutorial for this one as I couldn't get it to not timeout
// You needed to use maths to determine a formula for how to get the minimums
// You set the minimum to the first number and check the differences from there on

int main(void) {
    int repeats, smallest, smallestIndex;
    cin >> repeats;
    for (int i = 0; i < repeats; i++) {
        int numbers, minmax, minus = 0;
        vector<int> sequence;
        cin >> numbers;
        for (int j = 0; j < numbers; j++) {
            int num;
            cin >> num;
            sequence.push_back(num);
        }
        sort(sequence.begin(), sequence.end());
        minmax = sequence[0];
        for (int i = 0; i < sequence.size() - 1; i++) {
            if (sequence[i+1] - sequence[i] > minmax) minmax = sequence[i+1] - sequence[i];
        }
        cout << minmax << endl;
    }
}