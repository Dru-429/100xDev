#include <iostream> 
using namespace std;

int main() {
  long long num;
  cin >> num;
  long count = 0;
  
  for(long long i =1; i<=num/i; i++){
    if(num%i == 0){
      long j = num/i;
      if (i == j){
        count++;
      }
      else{
        count+=2;
      }
    }
  }

  cout << count << endl;
  return 0;

}