#include <iostream> 
using namespace std;

int main() {
  int num;
  bool isPrime = true;

  if(cin >> num){
    for(int i =2; i <= num/2; i++){
      if (num%i == 0){
        isPrime = false;
      }     
    }

    cout << (isPrime ? "Prime" : "Not Prime") << endl;
  }

  return 0;
}