#include <iostream>
using namespace std;

void spFactor(int num){
  bool isSpecial = false;
  
  for (int i=2; i<=num; i++){
    if (i%10 == 2 || i%10 ==7){
      if(num%i == 0 ){
        cout << i << " ";
        isSpecial = true;
      }
    }
  }
  cout <<(isSpecial ? "": "-1")  << endl;
}

int main() {
  int num;
  cin >> num;
  spFactor(num);

  return 0;
}