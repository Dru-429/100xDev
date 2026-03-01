#include <iostream>
using namespace std;

void rotate(long long len, int index, int arr[]) {
  for(long long i=index; i<len; i++){
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
  int num, index=0;
  cin >> num;

  while (num){
    long long len;
    cin >> len;
    int arr[len];

    for (long long  i=0; i<len; i++){
      cin >> arr[i];
    }
    cin >> index;
    rotate(len, index, arr );

    num--;
  }

  return 0;
}