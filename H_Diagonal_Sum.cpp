#include <iostream>
using namespace std;

int main(){
  int len; 
  cin >> len;
  int arr[len][len], sum=0;

  for (int i=0; i<len; i++){
    for (int j=0; j<len; j++){
      cin >> arr[i][j];
    }
  }

  for(int i=0; i<len; i++){
    for(int j=0; j<len; j++){
      if(i==j){
        sum += arr[i][j];
      }
    }
  }

  cout << sum << endl;

}