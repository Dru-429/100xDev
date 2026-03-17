#include <iostream>
using namespace std;

int main()
{
  int len;
  cin >> len;
  int arr[len];

  for (int i = 0; i < len; i++)
  {
    cin >> arr[i];
  }

  for (int i = 0; i < len; i++)
  {
    for (int j = i; j < len; j++)
    {
      for (int k = i; k <= j; k++)
      {
        cout << arr[k] << " ";
      }
      cout << endl;
    }
  }

  return 0;
}