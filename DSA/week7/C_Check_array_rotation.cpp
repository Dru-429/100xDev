#include <iostream>
using namespace std;

void checkRotation(long long len, int arr[]){
  int index=0;
  int min = arr[0];

  for (int i=0; i<len; i++){
    if(arr[i] <= min){
      index = i;
      min = arr[i];
    }
  }

  cout << index << endl;
}

int main() {
  int num; 
  cin >> num;

  while(num){
    long long len;
    cin >> len;
    int arr[len];

    for(int i=0; i<len; i++){
      cin >> arr[i];
    }

    checkRotation(len, arr);
    num--;
  }

  return 0;
}