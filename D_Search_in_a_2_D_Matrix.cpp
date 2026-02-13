#include <iostream>
using namespace std;

int main(){
  int n,m,find;
  bool isFound = false;
  cin >> n >> m >> find;
  int arr[n][m];

  for (int i=0; i<n; i++){
    for (int j=0; j<m; j++){
      cin >> arr[i][j];
    }
  }

  for (int i=0; i<n; i++){
    for(int j=0; j<m; j++){
      if(arr[i][j] == find){
        isFound = true;
        break;
      }
    }
  }
  cout << (isFound ? "true" : "false" ) << endl;

  return 0;
}