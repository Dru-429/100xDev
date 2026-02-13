#include <iostream>
using namespace std;

int main(){
  int n,m, oneCount, maxOnes=0;
  int maxRow= -1;
  cin >> n >> m;
  int arr[n][m];

  for(int i=0; i<n; i++){
    for (int j=0; j<m; j++){
      cin >> arr[i][j];
    }
  }

  for(int i=0; i<n; i++){
    oneCount=0;
    for (int j=0; j<m; j++){
      if(arr[i][j]==1){
        oneCount++;
      }
    }
    if(oneCount > maxOnes ){
      maxOnes = oneCount;
      maxRow = i;
    }
  }
  cout << maxRow << endl;

  return 0; 
}