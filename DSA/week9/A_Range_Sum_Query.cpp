#include <iostream>
using namespace std;

int main() {
  int len; 
  cin >> len;
  long long arr[len];
  long long prefArr[len];
  
  for(int i =0; i < len; i++) {
    cin >> arr[i];
  }
  for(int i =0; i<len; i++){
    prefArr[i] = arr[i] + (i > 0 ? prefArr[i-1] : 0);
  }

  int q;
  cin >> q;

  while (q--)
  {
    long long l, r;
    cin >> l >> r;
    l--;
    r--;
    long long sum = prefArr[r] - (l > 0 ? prefArr[l] : 0);
    cout << sum << endl;
  }

  return 0;
}