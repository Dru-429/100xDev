#include <iostream>
using namespace std;

bool binarySearch(string arr[],int len, string key){
  bool flag= false;
  int mid,left,right;
  left =0;
  right = len-1;

  while (left <= right)
  {
    mid = (right +left)/2;

    if( arr[mid] == key){
      flag = true;
      break;
    }
    else if( arr[mid] < key){
      left = mid +1;
    }
    else{
      right = mid-1;
    }
  }
  
  return flag;
}

int main(){
  int len;
  cin >> len;
  string arr[len];
  string key;
  
  for(int i=0; i<len; i++){
    cin >> arr[i];
  }
  cin >> key;

  cout << (binarySearch(arr, len, key) ? "YES" : "NO");

  return 0;
}