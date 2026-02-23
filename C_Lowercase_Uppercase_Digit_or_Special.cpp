#include <iostream>
using namespace std;

int main(){
  char val;
  cin >> val;

  if(val >= 'a' && val <= 'z'){
    cout << "Lowercase" << endl;
  }
  else if(val>='A' && val<='Z'){
    cout << "Uppercase" << endl;
  }
  else if(val>='0' && val <='9'){
    cout << "Digit" << endl;
  }
  else{
    cout << "Special" << endl;
  }

  return 0;
}