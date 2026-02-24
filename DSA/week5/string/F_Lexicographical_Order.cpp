#include <iostream> 
using namespace std;

int main() {
  string var1, var2;
  cin >> var1 >> var2 ;

  if(var1 > var2){
    cout << "B" << endl;
  }
  else if(var1 < var2){
    cout << "A" << endl;
  }
  else{
    cout << "Equal" << endl;
  }

  return 0;
}