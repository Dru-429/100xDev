#include <iostream>
using namespace std;

int main() {
  int len, q;
  cin >> len >> q;
  long long arr[len], prefixSq[len];

  for (int i = 0; i< len; i++){
    cin >> arr[i];
  }
  for (int i=0; i<len; i++){
    prefixSq[i] = (arr[i]*arr[i]) + ( i > 0 ? prefixSq[i-1] : 0);
  }

  while (q--)
  {
    int l, r;
    cin >> l >> r;
    l--; r--;
    long long sumSq = prefixSq[r] - (l > 0 ? prefixSq[l-1] : 0);
    cout << sumSq << endl; 
  }

  return 0;
}