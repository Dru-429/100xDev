#include <iostream>
using namespace std;

int main()
{
  int n, m;
  cin >> n >> m;
  int arr[n][m];
  bool flag = false;

  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      cin >> arr[i][j];
    }
  }

  if (!flag)
  {
    // left col
    for (int i = n - 1; i >= 0; i--)
    {
      if (arr[i][0] == -1)
      {
        flag = true;
        break;
      }
      cout << arr[i][0] << " ";
    }
  }

  if (!flag)
  {
    // top row
    for (int j = 1; j < m; j++)
    {
      cout << arr[0][j] << " ";
    }
  }

  if (!flag)
  {
    // right col
    for (int i = 1; i < n; i++)
    {
      if (arr[i][m - 1] == -1)
      {
        flag = true;
        break;
      }
      cout << arr[i][m - 1] << " ";
    }
  }

  if (!flag)
  {
    // bottom row
    for (int j = m - 2; j >= 1; j--)
    {
      if (arr[n - 1][j] == -1)
      {
        flag = true;
        break;
      }
      cout << arr[n - 1][j] << " ";
    }
  }

  cout << endl;
  return 0;
}