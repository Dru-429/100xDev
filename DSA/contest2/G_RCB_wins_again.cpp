#include <iostream>
using namespace std;

int main(){
  int n,midL,midR;
  cin >> n;
  long long arr[n];

  for(int i=0; i<n; i++){
    cin >> arr[i];
  }

  if(n%2==0){
    midL = n/2-1;
    midR = n/2;

    for(int i=midL; i >=0; i-- ){
      cout << arr[i] << " " << arr[midR] << " ";
      midL--;
      midR++;
    }
    cout << endl;
  }
  else{
    midL = n/2;
    midR = n/2 +1;

    cout << arr[midL--] << " ";
    for(int i=midL; i>=0; i--){
      cout << arr[i] << " " << arr[midR] << " ";
      midL--;
      midR++;
    }
  }

  return 0;
}