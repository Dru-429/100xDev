#include <iostream>
using namespace std;

long long factorial(int n){
  if(n==0 || n==1){
    return 1;
  }
  return n*factorial(n-1);
}

int main(){
  int a, b;
  cin >> a >> b;

  bool isSame = factorial(a) == factorial(b);
  cout << (isSame ? "Yes": "No");

  return 0;
}