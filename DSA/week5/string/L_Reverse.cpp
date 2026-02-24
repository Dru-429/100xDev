#include <iostream>
#include <string>

using namespace std;

int main() {
    string S;
    
    if (!(cin >> S)) return 0;
    for (int i = S.length() - 1; i >= 0; i--) {
        cout << S[i];
    }
    cout << endl;

    return 0;
}