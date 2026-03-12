#include <iostream>
using namespace std;

int main(){
  long long num;
  cin >> num;
  bool isPrime = true;

  if (num<2)
  {
    cout << "NO" << endl;
    return 0;
  }
  
  for (long long i = 2; i*i<=num; i++){
    if (num%i == 0){
      isPrime = false;
      break;
    }
  }

  cout << (isPrime ? "YES" : "NO") << endl; 
  return 0;
}