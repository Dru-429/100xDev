#include <iostream>
using namespace std;

int main() {
  int n;
  long long max,max_position=1;
  cin >> n;

  int a[n];
  for(int i =0; i < n; i++){
    cin >> a[i];
  }
  max = a[0];
  for(int i=0; i < n; i++){
    if(a[i]>max){
      max = a[i];
      max_position = (i+1);
    }
  }

  cout << max << " " <<max_position << endl;
  
  return 0;
}