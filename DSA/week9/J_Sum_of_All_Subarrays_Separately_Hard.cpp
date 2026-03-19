//use fast io
#include <iostream>
using namespace std;

int main() {
  
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int len;
  cin >> len;
  long long arr[len];

  for (int i =0; i<len; i++){
    cin >> arr[i];
  }

  for(int i = 0; i<len; i++){
    long long sum = 0;
    for(int j = i; j<len; j++){
      sum += arr[j];
      cout << sum << "\n";
    }
  }
  
  return 0;
}