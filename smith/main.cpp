#include <string>
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

vector<int> primes;

int main() {
	//calculate some prime numbers, because it's fun!
	int n = (int)sqrt(10000000001);
	n = 10; //remove me!
	primes.push_back(1);
	for(int i = 2; i < n; i++) {
		int candidate = i;
		bool prime = true;
		for(int j = 2; j < candidate && prime; j++) {
			if(candidate % j == 0) {
				prime = false;
			}
		}
		if(prime) {
			primes.push_back(candidate);
	//		cout << candidate << ", ";
		}
	}

	//read the stupid inputs	
	int sum_input, input, tmp;
	string line;
	int digit = 1;
	getline(cin, line);
	for(int i = line.length() - 1; i >= 0; i--) {
		tmp = line[i] - 48;
		sum_input = line[i];
		input += digit * tmp;
		digit = digit * 10;
	}
	
	//split number in its prime factors
	vector<int> prime_factors;
	int sum_primes;
	for(int i = 0; i < primes.size() && input > 1; i++) {
		while(input % primes[i] == 0 && input > 1) {
			input /= primes[i];
			prime_factors.push_back(primes[i]);
			sum_primes += primes[i];
		}
	}
	cout << "sum primes = " << sum_primes << ", sum input = " << sum_input << endl;
}
