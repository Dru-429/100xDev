#include <iostream>
using namespace std;

int main() {
  long long a, b;
  int countA = 0, countB=0;
  cin >> a >> b;

  //count a's factor
  for (long long i =1; i<=a/i; i++){
    if (a%i == 0){
      long j = a%i;
      j == i ? countA++ : countA += 2;
    }
  }
  //count 's factor
  for (long long i =1; i<=b/i; i++){
    if (b%i == 0){
      long j = a%i;
      j == i ? countB++ : countB += 2;
    }
  }

  if(countA == countB){
    cout << "DRAW" << endl;
  }
  else if (countA > countB){
    cout << "A" << endl;
  }
  else{
    cout << "B" << endl;
  }

  return 0;
}