#include <iostream>
#include <vector>
using namespace std;

int main(void) {
    int repeats;
    cin >> repeats;
    for (int i = 0; i < repeats; i++) {
        vector<int> array;
        for (int j = 0; j < 10; j++) cin >> array[j];
        int smallest = array[0];
        int smallestIndex = 0;
        for (int j = 0; j < 10; j++) if (array[j] < smallest) {
            smallest = array[j];
            smallestIndex = j;
        }
        array.erase(array.begin() + smallestIndex);
        smallest = array[0];
        for (int j = 0; j < array.size(); j++) if (array[j] < smallest) smallest = array[j];
        cout << smallest << endl;
    }
}