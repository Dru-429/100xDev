#include <iostream>
#include <set>
using namespace std;

int main(){
  int len1,len2;
  cin >> len1;
  int arr1[len1];
  set<int> st;

  for(int i=0;i<len1;i++){
    cin >> arr1[i];
  }

  cin >> len2;
  int arr2[len2]; 
  for(int i=0;i<len2;i++){
    cin >> arr2[i];
  }

  for (int i =0;i<len1; i++){
    st.insert(arr1[i]);
  }
  for (int i =0;i<len2; i++){
    st.insert(arr2[i]);
  }

  cout << st.size() << endl;
  for (auto it = st.begin(); it != st.end(); it++){
    cout << *it << " ";
  }

  return 0;

}