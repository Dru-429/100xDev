#include <iostream>
using namespace std;

int main () {
  int len, key;
  bool found = false;

  cin >> len;
  int arr[len];

  for ( int i = 0; i<len; i++) {
    cin >> arr[i];
  }
  cin >> key;

  for (auto i: arr) {
    if (i == key) {
      found = true;
      break;
    }
  }
  cout << (found ? "YES": "NO");
  
  return 0;
}