#include <iostream>
using namespace std;

int main() {
  int len, n;
  cin >> len;
  long long arr[len];
  long long prefEvenSum[len], sum = 0;

  for (int i=0; i<len; i++){
    cin >> arr[i];
  }
  for (int i=0; i< len; i++){
    if ((i+1)%2 == 0){
      prefEvenSum[i] = arr[i] + (i > 0? prefEvenSum[i-1]: 0 );
    }
    else
    {
      prefEvenSum[i] = (i > 0? prefEvenSum[i-1]: 0 );
    }
  }

  cin >> n;

  while (n--)
  {
    int l,r;
    cin >> l >> r;
    l--; r--;
    sum = prefEvenSum[r] - (l > 0 ? prefEvenSum[l-1] : 0);
    cout << sum << endl;
  }

  return 0;
}