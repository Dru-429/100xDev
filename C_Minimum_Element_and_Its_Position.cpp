#include <iostream>
using namespace std;

int main() {
  int n;
  long long min,min_position=1;
  cin >> n;

  int a[n];
  for(int i =0; i < n; i++){
    cin >> a[i];
  }
  min = a[0];
  for(int i=0; i < n; i++){
    if(a[i]<min){
      min = a[i];
      min_position = (i+1);
    }
  }

  cout << min << " " <<min_position << endl;
  
  return 0;
}