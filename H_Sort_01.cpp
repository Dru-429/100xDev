#include <iostream>
using namespace std;

void sort01(int arr[],int size){
  int zero,one;
  zero = one = 0;

  for(int i =0; i<size; i++){
    arr[i]==0 ? zero++ : one++; 
  }
  
  for(int i=0; i<zero; i++){
    cout << 0 << " ";
  }
  for(int i=0; i<one; i++){
    cout << 1 << " ";
  }
  cout << endl;
}

int main() {
  int n;
  cin >> n;

  for(int i=1; i <=n; i++){

    int size;
    cin >> size;
    int a[size];

    for (int i=0; i<size; i++){
      cin >> a[i];
    }

    sort01(a,size);
  }
  return 0;
}