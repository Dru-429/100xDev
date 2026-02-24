#include <iostream> 
using namespace std;

int main(){
  string str,newStr ="";
  char ch;
  cin >> str;

  for(int i=0; i<str.length(); i++){
    if(str[i] >= 'a' && str[i] <= 'z'){
      ch = str[i] - 32;
      newStr += ch;
    }
    else if(str[i] >= 'A' && str[i] <= 'Z') {
      ch = str[i] + 32;
      newStr += ch;
    }
    else{
      newStr += str[i];
    }
  }
  cout << newStr << endl;

  return 0;
}