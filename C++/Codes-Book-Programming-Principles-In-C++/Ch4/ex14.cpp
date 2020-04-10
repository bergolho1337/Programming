// Optimize prime number generator and checker using Sieve of Erastosthenes. O(N log logN)
// It find all primes in the range [0,max]

#include <iostream>
#include <vector>
#include <bitset>

using namespace std;

vector<int> primes;
bitset<10000010> bs;                // Can go up to 10^7 numbers

// It return the list of primes between [0,upperbound]
void sieve (long long int upperbound)
{
  long long sieve_size;
  sieve_size = upperbound;
  bs.set();                         // Set all bits to 1.
  bs[0] = bs[1] = 0;                // Don't count 1 and 0 as primes in the interval.
  for (long long int i = 2; i <= sieve_size; i++)
  {
    // If the number is not crossed.
    if (bs[i])
    {
      // Eliminate all of it's multiples beginning at j=i*i
      for (long long int j = i*i; j <= sieve_size; j += i)  // *Remember the test of primes <= sqrt(N)*
        bs[j] = 0;
      primes.push_back((int)i);
    }
  }
}

void listPrimes (long long int max)
{
  cout << "There are " << primes.size() << " primes." << endl;
  cout << "Listing all primes between [1," << max << "]" << endl;
  for (int i = 0; i < primes.size(); i++)
    cout << primes[i] << endl;
}

bool isPrime (long long int N, long long int max)
{
  // O(1) answer
  if (N <= max)
    return (bs[N]);
  // Check if the number is divible by the prime numbers in the list.
  for (int i = 0; i < primes.size(); i++)
    if (N % primes[i] == 0) return (false);
  return (true);
}

int main ()
{
  long long max;
  cout << "What is the max value: ";
  cin >> max;
  sieve(max);
  listPrimes(max);
  //cout << "Is " << 2147483647 << " prime ? " << isPrime(2147483647,max) << endl;          // 10 digit prime
  //cout << "Is " << 136117223861LL << " prime ? " << isPrime(136117223861LL,max) << endl;    // not prime, 104729*1299709
}
