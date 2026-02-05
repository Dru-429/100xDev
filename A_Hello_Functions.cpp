#include <iostream>
using namespace std;

void printLines(int n) {
    for (int i = 0; i < n; i++) {
        cout << "I am learning functions" << endl;
    }
}

int main() {
    int n;
    if (cin >> n) {
        printLines(n);
    }
    return 0;
}