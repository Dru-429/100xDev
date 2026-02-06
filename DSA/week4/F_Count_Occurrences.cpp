#include <iostream>
using namespace std;

int main() {
  int n, count=0;
  long long find;

  cin >> n >> find;
  long long a[n];

  for (int i=0; i<n; i++){
    cin >> a[i];
  }

  for (int i=0; i<n; i++){
    if( a[i]==find){
      count++;
    }
  }
  cout << count << endl;
  return 0;
}