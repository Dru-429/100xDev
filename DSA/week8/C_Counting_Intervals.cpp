#include <iostream>
using namespace std;

int main(){
  int n; 
  if (!(cin >> n)) return 0;
  while(n--){
    int t;
    long long a,b,interval =0;
    cin >> t >> a >> b;

    if(t==1){
      interval = b-a -1;
    }
    else if (t == 2 || t ==3)
    {
      interval = b-a;
    }
    else{
      interval = b-a + 1;
    }
    

    cout << interval << endl;
  }

  return 0;
}