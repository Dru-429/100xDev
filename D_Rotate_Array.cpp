#include <iostream>
using namespace std;

void rotate(int len, int index, int arr[]) {
  for(int i=index; i<len; i++){
    cout << arr[i] << " ";
    if (i == len-1){
      for(int j=0; j < index; j++){
        cout << arr[j] << " ";
      }
    }
  }
  cout<< endl;
}

int main(){
  int num, len, index=0;
  cin >> num;

  while (num){
    cin >> len;
    int arr[len];

    for (int i=0; i<len; i++){
      cin >> arr[i];
    }
    cin >> index;
    rotate(len, index, arr );

    num--;
  }

  return 0;
}