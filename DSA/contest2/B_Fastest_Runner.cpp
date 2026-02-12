#include <iostream>
using namespace std;

int fastestId(int size, long long time[]){
  long long min = time[0];
  int min_id = 1;
  
  for(int i=0; i<size; i++){
    if(time[i] <= min){
      min = time[i];
      min_id = i+1;
    }
  }

  return min_id;
}

int main(){
  int n;
  cin >> n;
  long long time[n];

  for(int i=0; i<n; i++){
    cin >> time[i];
  } 

  cout << fastestId(n, time) << endl;

  return 0;
}