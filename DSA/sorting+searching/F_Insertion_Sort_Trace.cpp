#include <iostream>
using namespace std;

void insSort(int arr[], int len)
{
  for (int i = 1; i < len; i++) {
    int j = i-1;
    int curr =  arr[i];
    int shifts = 0;

    while (j >= 0 && arr[j] > curr) {
      arr[j + 1] = arr[j];
      j--;
      shifts++;
    }
    arr[j + 1] = curr;

    // ---- Print this pass ----
    cout << "Pass " << i << ": ";

    // full array
    for (int k = 0; k < len; k++) {
      cout << arr[k];
      if (k != len - 1) cout << " ";
    }

    cout << " , ";

    for (int k = 0; k <= i; k++) {
      cout << arr[k];
      if (k != i) cout << " ";
    }

    cout << " |";

    for (int k = i + 1; k < len; k++) {
      cout << " " << arr[k];
    }
    if (i + 1 < len) cout << " ";

    cout << ", shifts = " << shifts << endl;
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

  insSort(arr, len);
  return 0;
}