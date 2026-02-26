#include <iostream>
using namespace std;

void bubbleSort(int arr[], int len){

  for(int i = len-1; i>=1; i--){
    bool swapped = false;
    int swappedCount = 0;

    for (int j=0; j<i; j++){
      if(arr[j] > arr[j+1]){
        swap(arr[j], arr[j+1]);
        swapped = true;
        swappedCount++;
      }
    }
    // if (!swapped)
    // {
    //   break;
    // }
    
    cout << "Pass " << len-i << ": " ;
    for(int k=0; k<len; k++){
      cout << arr[k] << " ";
    }
    cout << ", " << "swapped = " << swappedCount << endl;
    
  }
}

int main() {
  int len;
  cin >> len;
  int arr[len];

  for (int i=0; i<len; i++){
    cin >> arr[i];
  }

  bubbleSort(arr, len);
  return 0;
}