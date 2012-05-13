#include <iostream>
#include <string>
#include <algorithm>
#include <math.h>

using namespace std;

int main() {
	int M; //# datasets
	int
	cin >> M;
	cin.ignore(); //rest of the line
	cin.ignore(); //the blank line
	for(unsigned int m = 0; m < M; m++) {
		int N; //# of coins
		int K; //# of weightings
		cin >> N >> K;
		int coins[N];
		
		for(unsigned int k = 0; k < K; k++) { //make k weightings
			/** read the weighting **/
			int pi; //#coins left/right
			int left[pi], right[pi]; //tmp arrays to read the lines
			for(unsigned int i = 0; i < pi; i++)
				cin >> left[pi];
			for(unsigned int i = 0; i < pi; i++)
				cin >> right[pi];
			char op = '=';
			cin >> op;

			/** process **/
		}
	}
}
