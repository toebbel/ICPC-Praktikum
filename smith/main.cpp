#include <string>
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

vector<int> primes;

int main() {
	//calculate some prime numbers
	int n = (int)sqrt(10000000001);
	primes.push_back(1);
	for(int i = 2; i < n; i++) {
		int candidate = i;
		bool prime = true;
		for(int j = 1; j < candidate && prime; j++) {
			if(candidate % j == 0)
				prime = false;
		}
		if(prime) {
			primes.push_back(candidate);
			cout << candidate << ", ";
		}
	}

}
