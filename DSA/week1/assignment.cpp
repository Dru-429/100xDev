#include <iostream>;
using namespace std;

int main() {
  // cout << "*****" << endl;
  // cout << "   *" << endl;
  // cout << "  *" << endl;
  // cout << " *" << endl;
  // cout << "*****" << endl;

  // int n = 5;
  // for (int i=1; i<=10; i++ ){
  //   cout << n << "*" << i << "=" << n*i << endl;
  // }

  // int len,breadth;

  // if(cin >> len >> breadth){
  //   int area = len*breadth;
  //   int parimeter = 2*(len + breadth);

  //   cout << "Area = " << area << endl;
  //   cout << "Perimeter = " << parimeter << endl;
  // }

  // int n;
  // cin >> n;

  // for(int i=1; i <=10; i++) {
  //   cout << n << " * " << i << " = " << n*i << endl;
  // }

  // int n, m;

  // if(cin >> n >> m) {
  //   cout << n << " + " << m << " = " << n+m << endl ;
  //   cout << n << " - " << m << " = " << n-m << endl ;
  //   cout << n << " * " << m << " = " << n*m << endl ;
  //   cout << n << " / " << m << " = " << n/m << endl ;
  //   cout << n << " % " << m << " = " << n%m << endl ;
  // }

  // int n,m;

  // cin >> n >> m;
  // if( n> m ) {
  //   cout << "Min = " << m << endl;
  //   cout << "Max = " << n << endl;
  // }
  // else{
  //   cout<< "Min = " << n << endl;
  //   cout<< "Max = " << m << endl;
  // }

      int a,b,c ;
    
    cin >> a >> b >> c;
    
    int max = a;
    if (b >= max ){
        max = b;
    }
    if (c >= max){
        max = c;
    }
    
    int min = a;
    if (b <= min){
        min = b;
    }
    if (c <= min){
        min = c;
    }
    
    cout << "Min = " <<min << endl;
    cout << "Max = " <<max << endl;
    
  return 0;
}