#include <iostream>
using namespace std;

void swapAlt(int arr[], int size){
  for( int i=1; i<size; i+=2 ){
    swap(arr[i],arr[i-1]);
  }

  for(int i=0; i<size;i++){
    cout << arr[i] << " ";
  }
  cout << endl;
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

    swapAlt(a,size);
  }

  return 0;  
}