#include <iostream> 
using namespace std;

bool checkFactor(int num){
  int countFactor = 0;
  
  for (int i=1; i<=num; i++){
    if(num%i==0){
      countFactor++;
    }
    
    if(countFactor>=5){
      return false;
    }
  }
  return true;
}

int main() {
  int num;
  cin >> num;

  for (int i=1; i<=num; i++){
    if(checkFactor(i)){
      cout << i << " ";
    }
  }
  cout << endl;

  return 0;
}