#include <iostream>
#include <map>
using namespace std;

int main(){
  int len, q;
  cin >> len >> q;
  map<int, int> indexMap;

  for(int i = 0; i< len; i++){
    int x;
    cin >> x;

    if(indexMap.find(x) == indexMap.end()){
      indexMap[x] = i+1;
    }
  }

  while (q--)
  {
    int el;
    cin >> el;
    int ans = -1;
    auto it = indexMap.find(el);
    if (it != indexMap.end()){
      cout << it->second << endl;
    }
    else{
      cout << -1 << endl;
    }
  }
  return 0;
}
