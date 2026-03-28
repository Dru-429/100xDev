#include <iostream>
#include <set>
using namespace std;

int main () {
  int len;
  cin >> len;
  int arr[len];
  set <int>st;

  for (int i=0; i<len; i++){
    cin >> arr[i];
  }

  for(int i = 0; i <len; i++){
    st.clear();
    for (int j = i; j < len ; i++)
    {
      st.insert(arr[i]);
    }
    cout << st.size() << " ";
    cout << endl;
  }

}