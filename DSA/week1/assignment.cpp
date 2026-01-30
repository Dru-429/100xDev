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

  int len,breadth;

  if(cin >> len >> breadth){
    int area = len*breadth;
    int parimeter = 2*(len + breadth);

    cout << "Area = " << area << endl;
    cout << "Perimeter = " << parimeter << endl;
  }
  return 0;
}