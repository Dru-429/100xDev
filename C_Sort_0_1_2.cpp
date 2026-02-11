#include <iostream>;
using namespace std;

void sort012(int size, int arr[]){
  int zero, one, two;
  zero = one = two = 0;

  for (int i=0; i<size; i++){
    if(arr[i] == 0){
      zero++;
    }
    if(arr[i] == 1){
      one++;
    }
    if(arr[i] == 2){
      two++;
    }
  }

  while(two--){
    cout << 2 << " ";
  }
  while(one--){
    cout << 1 << " ";
  }
  while(zero--){
    cout << 0 << " ";
  }
  cout << endl;
}

int main(){
  int n;
  cin >> n;
  int arr[n];

  for (int i=0; i<n; i++){
    cin >> arr[i];
  }
  sort012(n, arr);

  return 0;
}