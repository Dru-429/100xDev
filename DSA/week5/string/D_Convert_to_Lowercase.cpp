#include <iostream>
using namespace std;

int main() {
  char val;
  cin >> val;

  if(val >='A' && val<='Z'){
    val += 32;
  }
  cout << val << endl;

  return 0;
}