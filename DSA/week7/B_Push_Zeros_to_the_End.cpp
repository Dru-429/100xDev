#include <iostream>
using namespace std;

void pushZero(int len, int arr[]){
  int zeros =0; 
   
  for (int i=0; i<len; i++){
    if(arr[i]==0){
      zeros++;
    }
    else{
      cout << arr[i] << " ";
    }
  }

  for(int i=0; i<zeros; i++){
    cout << 0 << " ";
  }
  cout<< endl;
}

int main(){
  int num, len;
  cin >> num;

  while(num){
    cin >> len;
    int arr[len];
    
    for(int i=0; i<len; i++){
      cin >> arr[i];
    }

    pushZero(len, arr);
    num--;
  }
  
  return 0;
}