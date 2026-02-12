#include <iostream>
using namespace std;

void Result(int maskArr[],int size, int passingMask){
  int pass,fail;
  pass = fail =0;

  for (int i=0; i<size; i++){
    maskArr[i] >= passingMask ? pass ++ : fail++ ;
  }

  cout << "Pass: " << pass << endl;
  cout << "Fail: " << fail << endl;
}

int main(){
  int n,passingMask;
  cin >> n;
  int a[n];

  for (int i=0; i<n; i++){
    cin >> a[i];
  }
  cin >> passingMask;

  Result(a, n, passingMask);

  return 0;
}