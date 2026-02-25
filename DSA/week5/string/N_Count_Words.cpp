#include <iostream>
using namespace std;

int main() {
  string str;
  int count= 1;
  getline(cin, str);

  for (int i=0; i<str.length(); i++){
    if(str[i] == ' '){
      count++;
    }
  }
  cout << count << endl;
  return 0;
}