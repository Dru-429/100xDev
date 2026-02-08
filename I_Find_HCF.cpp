#include <iostream>
using namespace std;

int hcf(int a, int b)
{
  while (b != 0)
  {
    int remainder = a % b;
    a = b;
    b = remainder;
  }
  return a;
}

int main()
{
  int a, b;
  cin >> a >> b;
  cout << hcf(a, b) << endl;

  return 0;
}