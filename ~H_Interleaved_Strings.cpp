#include <iostream>
using namespace std;

int main()
{
  string str, inter;
  cin >> str >> inter;
  int count =0;
  int total = str.length() + inter.length();

  for (int i = 0; i < max(str.length(), inter.length()); i++)
  {
    if (i < str.length())
    {
      cout << str[i];
      count++;
      if (count < total)
        cout << "-";
    }
    if (i < inter.length())
    {
      cout << inter[i];
      count++;
      if (count < total)
        cout << "-";
    }
  }
  cout << endl;

  return 0;
}