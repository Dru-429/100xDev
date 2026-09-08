#include <iostream>
using namespace std;

void slectionSort(int arr[], int len ){
  
  for (int i = 0; i< len - 1; i++) {
    int min = arr[i];
    int minIndex = i;
    for (int j = i; j<len; j++) {
      if (arr[j] < min) {
        min = arr[j];
        minIndex = j;
      }
    }
    swap(arr[i], arr[minIndex]);
    cout << "Pass " << i+1 << ": ";
    for (int k = 0; k<len; k++) {
      cout << arr[k] << " ";
    }
    cout << ", min_selected = "<< min << endl; 
  }
}

int main () {
  int len;
  cin >> len;
  int arr[len];

  for (int i =0; i<len; i++) {
    cin >> arr[i];
  }

  slectionSort(arr, len);
  return 0;
}