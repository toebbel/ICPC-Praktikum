#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

void erase(vector<bool> *in, vector<int> *items);

int main() {
	int M; //#testcases
	int N; //number of coins
	int K; //number of weightings
	
	cin >> M;

	for(unsigned int m = 0; m < M; m++) {
		if(m > 0)
			cout << endl;
		cin >> N >> K;
		vector<bool> tooBig(N, false);
		vector<bool> tooSmall(N, false);
		
		int pi;
		char op = '=';
		for(unsigned int k = 0; k < K; k++) {
			cin >> pi;
			vector<int> left(pi);
			vector<int> right(pi);

			for(unsigned int i = 0; i < pi; i++) {
				cin >> left[i];
				left[i]--;
			}
			for(unsigned int i = 0; i < pi; i++) {
				cin >> right[i];
				right[i]--;
			}
			cin >> op;

			/*/DEBUG--------
			for(unsigned int i = 0; i < pi; i++)
				cout << "left" << left[i] << endl;
			for(unsigned int i = 0; i < pi; i++)
				cout << "right" << right[i] << endl;
			cout << op << endl;
			//debug end*/
			
			if(op == '=' && op != '<') {
//				cout << "in tooBig:";
				erase(&tooBig, &left);
//				cout << "in tooSmall:";
				erase(&tooSmall, &right);

			}
			if (op == '=' && op != '>') {
//				cout << "in tooBig: ";
				erase(&tooBig, &right);
//				cout << "in tooSmall: ";
				erase(&tooSmall, &left);
			}
			if(op == '<' || op == '>') {
				bool all[N];
				for(unsigned int i = 0; i < N; i++)
					all[i] = true;
				for(int i = 0; i < N; i++) {
					if(find(right.begin(), right.end(), i) == right.end() && find(left.begin(), left.end(), i) == left.end())
						all[i] = false;
				}
				
				for(unsigned int i = 0; i < N; i++)
					if(!all[i]){
//						cout << "both: " << i << endl;
						tooBig[i] = true;
						tooSmall[i] = true;
					}
			}
			
			/*/DEBUG--------
			cout << "tooBig: ";
			for(unsigned int i = 0; i < N; i++) 
				cout << tooBig[i] << ", ";
			cout << endl << "tooSmall: ";
			for(unsigned int i = 0; i < N; i++)
				cout << tooSmall[i] << ", ";
			cout << endl;
			//debug end*/
		}
		
		int falseCoin_big = -1;
		int falseCoin_small = -1;
		for(unsigned int i = 0; i < N; i++) {
			if(!tooBig[i]) {
				if(falseCoin_big == -1) //first found candidate?
					falseCoin_big = i;
				else { //more than one candidate
					falseCoin_big = -1;
					break;
				}
			}
		}
		for(unsigned int i = 0; i < N; i++) {
			if(!tooSmall[i]) {
				if(falseCoin_small == -1) //first found candidate?
					falseCoin_small = i;
				else { //more than one candidate
					falseCoin_small = -1;
					break;
				}
			}
		}

		if((falseCoin_small == -1 && falseCoin_big == -1) || (falseCoin_small != -1 && falseCoin_big != -1 && falseCoin_big != falseCoin_small))
			cout << 0;
		else {
			if(falseCoin_small != -1)
				cout << (falseCoin_small + 1);
			else
				cout << (falseCoin_big + 1);
		}
		cout << endl;
	}
}

void erase(vector<bool> *in, vector<int> *elements) {
	for(vector<int>::iterator it = elements->begin(); it != elements->end(); ++it) {
//		cout << "remove " << *it << endl;
		(*in)[*it] = true;
	}
}

