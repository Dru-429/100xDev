#include<iostream>
#include<map>
using namespace std;

int main() {
  int n;
  cin >> n;
  map<int, int> elements;

  while(n--){
    int opt;
    cin >> opt;

    int e;
    if(opt == 1){
      cin >> e;
      if(elements.find(e) == elements.end()){
        elements[e] = 1;
      }
      else{
        elements[e]++;
      }
    }

    else if(opt == 2){
      cin >> e;
      if (elements.find(e) != elements.end())
      {
        elements[e]--;
        if (elements[e] <= 0){
          elements.erase(e);
        }
      }
    }
    
    else if (opt == 3){
      cout << elements.size() << endl;
    }
    else if (opt == 4){
      cin >> e;
      if (elements.find(e) != elements.end())
      {
        cout << "YES" << endl;
      }
      else{
        cout << "NO" << endl;
      }
    }
    else{
      return 0;
    }
  }

  return 0;
}