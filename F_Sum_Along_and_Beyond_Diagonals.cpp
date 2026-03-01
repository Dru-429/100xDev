#include <iostream>
using namespace std;

int main(){
  int len;
  long long daigSum =0, nonSum=0;
  cin >> len;
  long long arr[len][len];

  for(int i = 0; i<len; i++){
    for(int j =0; j<len; j++){
      cin >> arr[i][j];
    }
  }

  for(int i = 0; i<len; i++){
    for(int j =0; j<len; j++){

      if (i==j || (i+j == len-1))
      {
        daigSum += arr[i][j];
      }
      else{
        nonSum += arr[i][j];
      }
    }
  }

  cout << daigSum << " " << nonSum << endl;
  return 0;
}