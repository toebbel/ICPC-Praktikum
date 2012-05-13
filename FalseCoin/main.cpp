#include <iostream>
#include <string>
#include <algorithm>
#include <math.h>

using namespace std;

bool *coins = NULL;
void erase(int* range);

int main() {
	int M; //# datasets

	cin >> M;
	cin.ignore(); //rest of the line
	cin.ignore(); //the blank line
	for(unsigned int m = 0; m < M; m++) {
		int N; //# of coins
		int K; //# of weightings
		cin >> N >> K;
		coins = new bool[N];
		for(unsigned int i = 0; i < N; i++)
			coins[N] = true;
		
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
			if(op == '=' || op == '<') {
				erase(left);
			} 
			if(op == '=' || op == '>')
				erase(right);
			}
		}

		//find the (only) coin, that is still true
		int coin = 0;
		for(unsigned int i = 0; i < N; i++)
			if(coins[i]) 
				if(coin == 0)	//no coin found yet
					coin = i;
				else
					coin = -1; //there are multiple coins
		cout << ++coin << endl; //+1 because -1 -> 0 (no result) and coind-ids are not 0-based
	}
}

void erase(int* range) {
	unsigned int size = sizeof(range) / sizeof(int);
	for(unsigned int i = 0; i < size; i++) {
		cout << "set to false" << range[i] << endl; //DEBUG
		coins[range[i]] = false;
	}
}

