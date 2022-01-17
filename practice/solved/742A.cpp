#include <iostream>
using namespace std;

int main(void) {
    int n;
    cin >> n;
    int arr[] = {8, 4, 2, 6};
    n--;
    int pos = n < 0 ? 1 : arr[n%4];
    cout << pos << "\n";
    return 0;
}