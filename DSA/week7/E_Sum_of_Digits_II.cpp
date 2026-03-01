#include <iostream>
using namespace std;

int main(){
  string num;
  long long sum =0;
  cin >> num;

  for (int i=0; i<num.length(); i++){
    int digit = num[i]- '0';
    sum += digit;
  }
  cout << sum << endl;

  return 0;
}