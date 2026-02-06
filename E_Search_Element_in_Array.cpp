#include <iostream>
using namespace std;

int main() {
  int n;
  long long find;
  bool found=false;

  cin >> n >> find;
  long long a[n];

  for (int i=0; i<n; i++){
    cin >> a[i];
  }

  for (int i=0; i<n; i++){
    if( a[i]==find){
      found = true;
      break;
    }
  }
  cout << (found ? "YES" : "NO") << endl;
  return 0;
}