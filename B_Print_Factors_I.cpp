#include <iostream>
using namespace std;

void Print_factors(int n){
  for(int i=1; i<=n; i++){
    if(n%i == 0){
      cout<< i << " ";
    }
  }
}

int main() {
  int n;
  
  if (cin >> n) {
    Print_factors(n);
  }
  return 0;
}