#include <iostream>
using namespace std;

int main(){
  string str;
  cin >> str;
  int countA =0, countB=0;

  for (int i=0; i<str.size(); i++){
    if (str[i] == 'a' or str[i]== 'A') countA++;
    else countB++;
  }

  cout << (countA == countB ? "YES" : "NO") << endl; 

  return 0;
} 