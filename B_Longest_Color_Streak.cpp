#include <iostream>
using namespace std;

int main()
{
  int len;
  cin >> len;
  long long arr[len];
  int count = 1, countMax = 0;

  for (int i = 0; i < len; i++)
  {
    cin >> arr[i];
  }

  if (len == 0)
  {
    cout << 0 << endl;
    return 0;
  }
  for (int i = 1; i < len; i++)
  {
    if (arr[i] == arr[i-1])
    {
      count++;
    }
    else{
      count = 1;
    }
    
    if (count >= countMax){
      countMax = count;
    }
  }

  cout << countMax << endl;

  return 0;
}