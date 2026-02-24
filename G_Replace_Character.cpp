#include <iostream>
using namespace std;

int main() {
  string str;
  char val1, val2;
  cin >> str >> val1 >> val2 ;

  for (int i=0; i<str.length(); i++){
    if (str[i] == val1){
      str[i] = val2;
    }
  }
  cout << str << endl;

  return 0;
}