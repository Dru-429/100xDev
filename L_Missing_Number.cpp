#include <iostream>
using namespace std;

void missingNo(int arr[], int size){
  for (int i=0; i<size; i++){
    int count=0;
    
    for (int j=0; j<size; j++){
      if(arr[j] == arr[i]){
        count++;
      }
    }

    if(count%2 != 0){
      cout << arr[i] << endl;
      break;
    }
  }
}

int main() {
  int n;
  cin >> n;
  
  while(n--){
    int size;
    cin >> size;
    int a[size];
  
    for(int i=0; i<size; i++){
      cin >> a[i];
    }

    missingNo(a,size);
  }

  return 0;  
}