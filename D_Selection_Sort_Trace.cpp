#include <iostream>
using namespace std;

void selectionSort(int arr[], int len) {
  for(int i=0; i<len-1; i++){
    int min = i;
    for(int j=i+1; j<len; j++){
      if (arr[j] < arr[min])
      {
        min = j;
      }
    }
    swap(arr[i], arr[min]);

    cout << "Pass " << i+1 << ": " ;
    for(int k=0; k<len; k++){
      cout << arr[k] << " ";
    } 
    cout << ", " << "min_selected = " << arr[i] << endl;
  }
}

int main() {
  int len;
  cin >> len;
  int arr[len];

  for (int i = 0; i < len; i++) {
    cin >> arr[i];
  }

  selectionSort(arr,len);
  return 0;
}