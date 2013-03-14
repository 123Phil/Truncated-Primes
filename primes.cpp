#include <iostream>
#include <vector>
using namespace std;

#define MAX 1000000

bool catPrime(int n, vector<int>& primes);
bool isPrime(int n);
void Truncate(int &n);


int main()
{
	vector<int> primes;
	int primer;
	int numElems = 0;

	primes.push_back(3);
	primes.push_back(7);

	for (primer = 13; primer < MAX; primer++)
		{
		if(catPrime(primer, primes))
			primes.push_back(primer);
		}

	numElems = primes.size();

	int i;
	for(i = 0; i < numElems; i++)
		cout << primes[i] << endl;

	return 0;
}

bool isPrime(int n)
{
	if (n < 2) return false;

	int i;
	for(i = 2; i*i <= n; i++)
		if (n%i == 0) return false;

	return true;
}

bool catPrime(int n, vector<int>& primes)
{
	if (!isPrime(n)) return false;

	Truncate(n);
	
	int i;
	int numElems = primes.size();
	for (i = 0; i < numElems; i++)
		if (n == primes[i]) return true;
	
	return false;
}


void Truncate(int &n)
{
	int i = 0;
	int dup = n;
	while (dup >= 10)
		{
		dup /= 10;
		i++;
		}
	while (i > 0)
		{
		dup *= 10;
		i--;
		}
	
	n -= dup;
}
