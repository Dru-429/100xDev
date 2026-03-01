#include <iostream>
using namespace std;

int main()
{
  int len, largest, secLarge = 0;
  cin >> len;
  int arr[len];

  for (int i = 0; i < len; i++)
  {
    cin >> arr[i];
  }
  largest = arr[0];

  for (int i = 0; i < len; i++)
  {
    if (arr[i] >= largest || arr[i] >= secLarge)
    {
      if (arr[i] >= largest)
      {
        secLarge = largest;
        largest = arr[i];
      }
      else
      {
        secLarge = arr[i];
      }
    }
  }
  cout << (largest == secLarge ? -1 : secLarge);

  return 0;
}