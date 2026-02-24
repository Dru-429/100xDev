#include <iostream>
#include <string>
using namespace std;

int main() {
  string str, newStr ="";
  getline(cin,str);

  for (int i=0; i<str.length(); i++){
    if(str[i] != ' '){
      newStr += str[i];
    }
  }
  cout << newStr << endl;

  return 0;
}