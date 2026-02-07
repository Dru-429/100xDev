#include <iostream>
using namespace std;

void intersection(int arr[], int m, int arr2[], int l){
  bool used[l];

  for( int i=0; i<m; i++){

    for( int j=0; j<l; j++){
      if( !used[j] && arr[i] == arr2[j]){
        cout << arr[i] << " ";
        used[j] = true;
        break;
      }
    }
  }

  cout << endl;
}

int main(){
  int n;
  cin >> n;

  while(n--){
    int m,l;
    
    cin >> m;
    int arr[m];
    for(int i=0; i<m; i++ ){
      cin >> arr[i];
    }

    cin >> l;
    int arr2[l];
    for(int i=0; i<l; i++ ){
      cin >> arr2[i];
    }
    
    intersection(arr, m, arr2, l);
  }

  return 0;
}