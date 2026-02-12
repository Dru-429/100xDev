#include <iostream>
using namespace std;

int main(){
  int n;
  cin >> n ;
  long long arr[n];
  bool flag=false;

  for (int i=0; i<n; i++ ){
    cin >> arr[i];
  }
  long long num = arr[0];

  for(int i=0; i<n; i++){
    if( arr[i] != num){
      flag = true;
      break;
    }
  }
  cout << (flag ? "NO": "YES") << endl;
  
  return 0;
}