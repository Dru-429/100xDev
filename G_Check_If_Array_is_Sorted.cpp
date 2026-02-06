#include <iostream>
using namespace std;

int main() {
  int n;
  bool flag=false;
  cin >> n;

  int a[n];
  for(int i =0; i < n; i++){
    cin >> a[i];
  }
  
  for(int i=1; i < n; i++){
    if (a[i] < a[i-1])
    {
      flag = true;
      break;
    }
  }
  cout << (flag ? "NO" : "YES") << endl;
  return 0;
}