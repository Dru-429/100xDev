#include <iostream>
using namespace std;

long long factorial(int num){
  long long result=1;
  for (int i=1; i<=num; i++){
    result*=i;
  }
  return result;
}

long long ncr(int n, int r){
  return (factorial(n) / (factorial(r)*factorial(n-r))) ;
}

int main(){
  int n,r;

  cin >> n >> r;
  cout << ncr(n, r) << endl;

  return 0;
}