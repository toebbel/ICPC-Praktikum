#include <iostream>
#include <string>
#include <algorithm>
#include <math.h>

#define DEBUG

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
		#ifdef DEBUG
			cout << "N=" << N << ", K=" << K << endl;
		#endif
		coins = new bool[N];
		for(unsigned int i = 0; i < N; i++)
			coins[N] = true;
		
		for(unsigned int k = 0; k < K; k++) { //make k weightings
			/** read the weighting **/
			int pi; //#coins left/right
			cin >> pi;
			#ifdef DEBUG
				cout << "there will be " << pi << " coins on each side" << endl;
			#endif
			int left[pi], right[pi]; //tmp arrays to read the lines
			for(unsigned int i = 0; i < pi; i++) {
				cin >> left[pi];
				#ifdef DEBUG
					cout << "read " << left[pi] << endl;
				#endif
			}
			#ifdef DEBUG
				cout << "now right";
			#endif
			for(unsigned int i = 0; i < pi; i++) {
				cin >> right[pi];
				#ifdef DEBUG
					cout << "read " << right[pi] << endl;
				#endif
			}
			char op = '=';
			cin >> op;
			
			/** process **/
			if(op == '=' || op == '<') {
				#ifdef DEBUG
					cout << "erase left (op " << op << ")" << endl;
				#endif
				erase(left);
			}
			 
			if(op == '=' || op == '>') {
				#ifdef DEBUG
					cout << "erase right (op " << op << ")" << endl;
				#endif
				erase(right);
			}
			
		}

		//find the (only) coin, that is still true
		int coin = 0;
		for(unsigned int i = 0; i < N; i++)
			if(coins[i]) { 
				#ifdef DEBUG
					cout << "coin " << i << " is candidate" << endl;
				#endif
				if(coin == 0)	//no coin found yet
					coin = i;
				else {
					coin = -1; //there are multiple coins
		cout << ++coin << endl; //+1 because -1 -> 0 (no result) and coind-ids are not 0-based
				#ifdef DEBUG
					cout << "more than one candidate!" << endl;
				#endif
				}
			}
	}
}

void erase(int* range) {
	unsigned int size = sizeof(range) / sizeof(int);
	for(unsigned int i = 0; i < size; i++) {
		cout << "set to false" << range[i] << endl; //DEBUG
		coins[range[i]] = false;
	}
}

