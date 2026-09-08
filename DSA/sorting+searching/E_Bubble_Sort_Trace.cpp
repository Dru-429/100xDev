#include <iostream>
using namespace std;

void bubbleSort(int arr[], int len)
{
  for (int i = len - 1; i > 0; i--)
  {
    int swaps = 0;
    bool swaped = false;

    for (int j = 0; j < i; j++)
    {
      if (arr[j] > arr[j + 1])
      {
        swap(arr[j], arr[j + 1]);
        swaps++;
        swaped = true;
      }
    }

    cout << "Pass " << len -i  << ": ";
    for (int k = 0; k < len; k++)
    {
      cout << arr[k] << " ";
    }
    cout << ", swaps  = " <<  swaps << endl;
    if (!swaped)
    {
      break; 
    }
  }
}

int main()
{
  int len;
  cin >> len;
  int arr[len];

  for (int i = 0; i < len; i++)
  {
    cin >> arr[i];
  }

  bubbleSort(arr, len);
  return 0;
}