#include <iostream>
using namespace std;

void checkPrime(long long num)
{
    if (num < 2) {
        cout << "Not Prime" << endl;
        return;
    }

    bool isPrime = true;
    // Optimization: Loop up to sqrt(num) using i*i <= num
    for (long long i = 2; i * i <= num; i++)
    {
        if (num % i == 0)
        {
            isPrime = false;
            break; 
        }
    }
    
    cout << (isPrime ? "Prime" : "Not Prime") << endl;
}

int main()
{
  long long num;

  if (cin >> num){
    checkPrime(num);
  }
  return 0;
}