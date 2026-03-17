#include <iostream>
using namespace std;

int main()
{
  int len,t;
  string str;
  cin >> len;
  int prefVowel[len];
  cin >> str;

  for(int i = 0; i<len; i++){
    char ch = str[i];
    if(ch =='a' || ch =='e' || ch =='i' || ch == 'o' || ch =='u'){
      prefVowel[i] = 1 + (i>0? prefVowel[i-1] : 0);
    }
    else{
      prefVowel[i] = (i>0? prefVowel[i-1] : 0);
    }
  }
  cin >> t;
  
  while (t--)
  {
    int l,r;
    cin >> l >> r;
    l--; r--;
    int count = prefVowel[r] - (l>0 ? prefVowel[l-1] : 0 );
    cout << count << endl;
  }
  
  return 0;
}