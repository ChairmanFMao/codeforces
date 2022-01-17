#include <iostream>
#include <vector>
#include <bits/stdc++.h>
#include <cmath>
using namespace std;

int main(void) {
    int repeats;
    cin >> repeats;
    for (int i = 0; i < repeats; i++) {
        int n;
        cin >> n;
        vector<int> numbers;
        for (int j = 0; j < n; j++) {
            int a;
            cin >> a;
            numbers.push_back(a);
        }
        sort(numbers.begin(), numbers.end());
        int smallest = numbers[0];
        int b = 0;
        bool one = false;
        while (numbers[b] == numbers[0]) {
            b++;
            if (b == numbers.size()){
                one = true;
                break;
            }
        }
        if (one) {
            cout << -1 << endl;
            continue;
        }
        int dif = numbers[b] - smallest;
        bool allDiv = true;
        while (allDiv) {
            allDiv = false;
            for (int j = 2; j < numbers.size(); j++) { 
                if (abs(numbers[j] - smallest) % dif != 0){
                    allDiv = true;
                    break;
                }
            }
            dif--;
        }
        cout << dif + 1 << endl;
    }
    return 0;
}