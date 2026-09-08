#include <iostream>
using namespace std;

void merge(int arr1[], int arr2[], int l1, int l2) {
  int i,j,k;
  i = j = k =0;
  int res[l1+l2];

  while(i < l1  && j <l2) {
    if (arr1[i] < arr2[j]) {
      res[k] = arr1[i];
      i++;
    }
    else {
      res[k] = arr2[j];
      j++;
    }
    k++;
  }
  
  while (i < l1){
    res[k] = arr1[i];
    k++;
    i++;
  }
  while (j < l2){
    res[k] = arr2[j];
    k++;
    j++;
  }

  for (int i = 0; i<k; i++) {
    cout << res[i] << " " ;
  }
  cout << endl;
}

int main () {
  int l1, l2;
  cin >> l1 >> l2;
  int arr1[l1], arr2[l2];

  for (int i =0; i<l1; i++) {
    cin >> arr1[i];
  }
  for (int i=0; i<l2; i++) {
    cin >> arr2[i];
  }

  merge(arr1, arr2, l1, l2);
  return 0;
}