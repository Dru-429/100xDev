#include <iostream>
using namespace std;

int main() {
  int hh, mm;
  char sep;
  cin >> hh >> sep >> mm;

  if(hh == mm){
    cout << "Mogambo is happy"<< endl;
  }
  else{
    cout << "Mogambo is sad" << endl;
  }

  return 0;
}