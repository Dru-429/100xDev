#include <iostream>
using namespace std;

int main()
{
  string str;
  cin >> str;

  for (int i = 0; i < str.length(); i++)
  {
    if (str[i] >= 'a' && str[i] <= 'z')
    {
      char ch = (str[i] - 32);
      cout << ch;
    }
    else
    {
      char ch = (str[i] + 32);
      cout << ch;
    }
  }
  cout << endl;

  return 0;
}