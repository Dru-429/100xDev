#include <iostream>
using namespace std;

long long countZeros(string num){
  long long count_zero=0;
  for (int i=0; i< num.length(); i++ ){
    if(num[i] == '0'){
      count_zero++;
    }
  }
  return count_zero;
}

int main(){
  string num;

  cin >> num;
  cout << countZeros(num) << endl;

  return 0;
}