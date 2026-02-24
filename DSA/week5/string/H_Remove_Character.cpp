#include <iostream>
using namespace std;

int main() {
  string str, newStr ="";
  char val1;
  cin >> str >> val1 ;

  for (int i=0; i<str.length(); i++){
    if(str[i] != val1){
      newStr += str[i];
    }
  }
  cout << newStr << endl;

  return 0;
}