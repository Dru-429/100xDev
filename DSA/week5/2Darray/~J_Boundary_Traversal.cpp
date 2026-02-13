#include <iostream>
using namespace std;

int main(){
  int n,m;
  cin >> n >> m;

  if (n==1)
  {
    long long arr[m];
    for (int i=0; i<m; i++){
      cin >> arr[i];
    }

    for (int i=0; i<m; i++){
      cout << arr[i] << " ";
    }
  }
  else if(m==1){
    long long arr[n][m];
    for(int i=0; i<n; i++){
      cin >> arr[i][0];
    }
    for (int i=0; i<n; i++){
      cout << arr[i][0] << " ";
    }
  }
  else{
    long long arr[n][m];
    for (int i=0; i<n; i++){
      for (int j=0; j<m; j++){
        cin >> arr[i][j];
      }
    }

    //top row
    for (int i=0; i<n; i++){
      cout << arr[i][0] << " ";
    }

    //right column
    for (int j=1; j<n; j++){
      cout << arr[j][m-1] << " ";
    }

    //bottom row 
    for (int i=m-2; i>=0; i--){
      cout << arr[n-1][i] << " ";
    }

    //left column
    for (int j=n-2; j>0; j--){
      cout << arr[j][0] << " ";
    }
  }
  cout << endl;
  
  return 0;
}