#include <iostream>
using namespace std;

int main() {
  int len, q, k;
  cin >> len >> q >> k;
  long long arr[len];
  int prefixSum[len];

  for(int i =0;i<len; i++){
    cin>> arr[i];
  }
  for(int i=0; i<len; i++){
    int count = 1, num = arr[i];
    for (int i = 1; i < num; i++){
      if (num % i == 0){
        count++;
      }
      if (count > k){
        break;
      }
    }

    prefixSum[i] = (count == k ? 1:0) + (i > 0 ? prefixSum[i-1] : 0);
  }

  while (q--)
  {
    int l,r;
    cin >> l >> r;
    l--, r--;

    int count = prefixSum[r] - (l > 0 ? prefixSum[l-1] : 0);
    cout << count << endl;
  }

  return 0;
}