#include <iostream>
using namespace std;

int main(){
  int n;
  cin >> n;

  while (n--)
  {
    long long a,b, sum =0;
    cin >> a >> b;
    if(a==b){
      sum = a;
    }
    else if( a != 1 && b != 1){
      long long sumB = b*(b+1)/2;
      --a;
      long long sumA = a*(a+1)/2;
      sum = sumB - sumA;
    }
    else{
      sum = b*(b+1)/2;
    }
    cout << sum << endl;
  }
  return 0;
  
}