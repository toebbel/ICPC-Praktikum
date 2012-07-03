#include <string>
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

vector<int> primes;

int main() {
	//calculate some prime numbers
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
	
	int sum_input, input, tmp;
	string line;
	int digit = 1;
	getline(cin, line);
	for(int i = line.length() - 1; i >= 0; i--) {
		tmp = line[i] - 48;
		cout << tmp << "-";
		sum_input = line[i];
		input += digit * tmp;
		digit = digit * 10;
	}
	cout << "=" << input << endl;
}
