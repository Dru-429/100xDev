#include <iostream>
using namespace std;

bool binary_search(int arr[], int len, int key){
  int mid,left =0, right = len-1;

  while (left <= right) {
    int mid = (left + right) / 2;

    if (arr[mid] == key) {
      return true;
    }
    else if (arr[mid]> key) {
      right = mid - 1;
    }
    else {
      left = mid + 1;
    }
  }

  return false;
}

int main () {
  int len, key;
  cin >> len;

  int arr[len];
  for (int i = 0; i < len; i++)  {
    cin >> arr[i];
  }
  cin >> key;

  cout << (binary_search(arr,len, key) ? "YES" : "NO") << endl;

  return 0;
}