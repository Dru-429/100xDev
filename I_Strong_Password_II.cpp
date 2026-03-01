#include <iostream>
using namespace std;

int main (){
  string pass;
  cin >> pass;
  int upper, lower, spChar, num;
  upper = lower = spChar = num = 0;
  string type = "Weak";
  bool flag = false;

  for (int i=0; i<pass.length(); i++){
    if(pass[i] >= 'a' && pass[i] <= 'z'){
      lower++;
    }
    else if(pass[i] >= 'A' && pass[i] <= 'Z'){
      upper++;
    }
    else if (pass[i] >= '0' && pass[i] <= '9'){
      num++;
    }
    else{
      spChar++;
    }

    if(upper >= 1 && lower >=1 && spChar >= 1 && num >= 1){
      type = "Strong";
    }
    else if(upper >= 1 && lower >=1 && spChar >= 1){
      type = "Moderate";
    }
    else if(upper >= 1 && lower >=1 && num >= 1){
      type = "Moderate";
    }
    else if(upper >= 1 && spChar >= 1 && num >= 1){
      type = "Moderate";
    }
    else if(lower >= 1 && spChar >= 1 && num >= 1){
      type = "Moderate";
    }
    else{
      type = "Weak";
    }
  }
  if(!false){
    cout << type << endl;
  }

  return 0;
}