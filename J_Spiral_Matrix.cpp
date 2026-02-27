#include <iostream>
using namespace std;  

int main(){
  int n,m;
  cin >> n >> m;
  int arr[n][m];

  for (int i=0; i<n; i++){
    for(int j=0; j<m; j++){
      cin >> arr[i][j];
    }
  }

  int sr=0, er=n -1;
  int sc=0, ec=m -1;

  while(sr <= er && sc <= ec){

    //sr (sc--> ec)
    for(int j= sc; j<=ec; j++){
      cout << arr[sr][j];
    }

    //ec(sr +1 --> er)
    for(int i=sr+1; i<=er; i++ ){
      cout << arr[i][ec];
    }

    //er(ec-1 --> sc)
    for(int j=)

    //sc(er -1==> sr+1)

  }

  //start row
  for(int j=0; j<m; j++){
    cout << arr[0][j] << " ";
  }

  //end col
  for(int i=1; i<n; i++){
    cout << arr[i][m-1] << " ";
  }

  return 0;
}