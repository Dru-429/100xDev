#include <iostream> 
using namespace std;

int isPrime(int num){
  for(int i=2; i*i <=num; i++){
    if(num % i == 0){
      return 0;
    }
  }
  return 1;
}

int main(){
  int n;
  cin >> n;

  if(n < 2){
    return 0;
  }
  for (int i=2; i<=n; i++){
    if(isPrime(i)){
      cout << i << " ";
    }
  }

  return 0;
}