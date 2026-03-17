#include <iostream>
using namespace std;

int main()
{
  int len, q;
  cin >> len >> q;
  long long arr[len];
  int prefixSum[len];

  for (int i = 0; i < len; i++)
  {
    cin >> arr[i];
  }

  for (int i = 0; i < len; i++)
  {
    long long val = (i % 2 == 0) ? arr[i] : -arr[i];
    prefixSum[i] = (i > 0 ? prefixSum[i - 1] : 0) + val;
  }

  while (q--)
  {
    int l, r;
    cin >> l >> r;
    l--, r--;
    long long count = prefixSum[r] - (l > 0 ? prefixSum[l - 1] : 0);
    cout << (count > 0 ? count : -count) << endl;
  }

  return 0;
}