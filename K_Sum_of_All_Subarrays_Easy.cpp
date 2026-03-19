#include <iostream>
using namespace std;

int main(){
  int len;
  cin >> len;
  long long arr[len];

  for (int i = 0; i < len; i++){
    cin >> arr[i];
  }

  long long sum = 0;
  for (int i =0; i< len; i++){
    long long Sepsum = 0;
    for (int j = i; j<len; j++){
      Sepsum += arr[j];
      sum += Sepsum;
    }
  }

  cout << sum << endl;
  return 0;
}
