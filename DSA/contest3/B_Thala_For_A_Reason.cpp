#include <iostream>
using namespace std;

int main(){
  int t;
  cin >> t;

  while (t){
    string str;
    cin >> str;
    int sum = 0;

    for (int i=0; i<str.length(); i++){
      sum += (str[i] - '0');
    }
    cout << (sum == 7 ? "Thala for a reason" : "Blocked for no reason") << endl;
    t--;
  }

  return 0;
}