#include <iostream>
using namespace std;  

int main(){
  int len;
  cin >> len;
  int arr[len][len];

  for (int i=0; i<len; i++){
    for(int j=0; j<len; j++){
      cin >> arr[i][j];
    }
  }

  for(int j =0; j<len; j++){
    for (int i =len-1; i>=0; i--){
      cout << arr[i][j] << " ";
    }
    cout << endl;
  }

  return 0;
}