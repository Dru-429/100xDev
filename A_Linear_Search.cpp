#include <iostream>
using namespace std;

bool linearSearch(int arr[],int len, int key){
  bool flag = false;

  for(int i=0; i<len; i++){
    if(arr[i] == key){
      flag =true;
      break;
    }
  }
  return flag;
}

int main(){
  int len,key;
  cin >> len;
  int arr[len];
  
  for(int i=0; i<len; i++){
    cin >> arr[i];
  }
  cin >> key;

  cout << (linearSearch(arr, len, key) ? "YES" : "NO");

  return 0;
}