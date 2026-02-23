#include <iostream> 
using namespace std;

int main() {
  string f1,f2,l1,l2;
  bool related = false;
  cin >> f1 >> l1;
  cin >> f2 >> l2;

  if(l1 == l2){
    related = true;
  } 

  cout << (related ? "YES" : "NO");
  return 0;
}