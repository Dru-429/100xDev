#include <iostream>
#include <set>
using namespace std;

int main(){
  int len;
  cin >> len;
  long long arr[len];
  int counter =0;
  set<int> st;

  for(int i = 0; i < len; i++){
    cin >> arr[i];
  }

  for(int i =0; i<len; i++){
    if (st.count(arr[i]) == 0 )
    {
      st.insert(arr[i]);
      counter++;
    }
  }
  cout << counter << endl;

  return 0;
}