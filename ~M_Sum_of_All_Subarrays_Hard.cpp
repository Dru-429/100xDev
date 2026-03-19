#include <iostream>
using namespace std;

int main() {
  int len;
  cin >> len;
  long long arr[len];

  for (int i = 0; i < len; i++) {
    cin >> arr[i];
  }

  long long sum = 0;
  for (int i =0; i< len; i++){
    int occ = (len-i) + (len-i)*i;
    sum += arr[i] * occ;
  }
  cout << sum << endl;

  return 0; 
}