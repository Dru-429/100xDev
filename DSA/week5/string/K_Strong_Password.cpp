#include <iostream>
using namespace std;

int main() {
  string str;
  bool strnght = false;
  int num,spChar,up,low;
  num = spChar = up = low = 0;
  cin >> str;

  for(int i=0; i< str.length(); i++){ 
    if( str[i] >= 'A' && str[i]<= 'Z'){
      up++;
    }
    else if( str[i] >= 'a' && str[i]<= 'z'){
      low++;
    }
    else if( str[i] >= '0' && str[i]<= '9'){
      num++;
    }
    else{
      spChar++;
    }

    if(num >= 1 && spChar >= 1 && up >= 1 && low >= 1){
      strnght = true;
      break;
    }
  }

  if(str.length() != 10){
    cout << "Weak" << endl;
  }
  else{
    cout << (strnght ? "Strong" : "Weak") << endl;  
  }

  return 0;
}