#include <string>
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

vector<int> primes;
bool isSmith(int line);
bool isPrime(int line);

int main() {
	//calculate some prime numbers, because it's fun!
	int n = sqrt(1000000001);
//	n =(int) sqrt(4937775); //remove me!
	for(int i = 2; i < n; i++) {
		int candidate = i;
		bool prime = true;
		for(int j = 2; j < sqrt(candidate) && prime; j++) {
			if(candidate % j == 0) {
				prime = false;
			}
		}
		if(prime) {
			primes.push_back(candidate);
	//		cout << candidate << ", ";
		}
	}
//	cout << "ready for input" << endl;

	int line;
	while(cin >> line) {
		line++;
		while(!isSmith(line) || isPrime(line) || line == 1) {
			line++;
		}
		cout << line << endl;
	}
}

bool isPrime(int line) {
	for(int j = 2; j < sqrt(line); j++)
		if(line % j == 0)
			return false;
	return true;
}

bool isSmith(int line) {
	//read the stupid inputs	
	int sum_input = 0;
	int input = line;
	while(line > 0) {
		sum_input += line % 10;
		line /= 10;
	}

	
//	cout << "splitting" << endl;
	//split number in its prime factors
	vector<int> prime_factors;
	int sum_primes = 0;
	for(unsigned int i = 0; i < primes.size() && input > 1; i++) {
		while(input % primes[i] == 0 && input > 1) {
			input /= primes[i];
			prime_factors.push_back(primes[i]);
			sum_primes += primes[i];
			//cout << primes[i] << "-";
		}
	}
	while(input > 0) {
		sum_primes += input % 10;
		input /= 10;
	}

	//cout << "sum primes = " << sum_primes << ", sum input = " << sum_input << endl;
	return sum_primes == sum_input;
	
}

