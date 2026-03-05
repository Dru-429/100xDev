#include <iostream>
using namespace std;


int main(){
  int num; 
  cin >> num;
  long long total = 0, max =0, min =0, avg =0;
  
  for(int i=0; i<num; i++){
    long long amount;
    cin >> amount;
    total += amount;

    if(i==0){
      max = amount;
      min = amount;
    }

    if(amount > max){
      max = amount;
    }
    
    if(amount < min){
      min = amount;
    }
  }
  avg = total/num;
  cout << total << " " << max << " " << min << " " << avg;

  return 0;
}