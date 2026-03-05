#include <iostream>
using namespace std;

int main(){
  int n,m, num =1;
  cin >> n >> m;
  char ch = 'a';

  for(int i =0; i <n; i++){
    if (i%2 !=0)
    {
      for(int j=0; j<m; j++){
        if(num==9){
          num =0;
        }
        if (ch == 'z'){
          ch = 'a';
        }
  
        if(j%2==0){
          cout << num;
          num++;
        }
        else{
          cout << ch;
          ch++;
        }
      }
      cout << endl;
    }
    else{}

  }
  
  return 0;
}