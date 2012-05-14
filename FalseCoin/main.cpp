#include <vector>
#include <iostream>

using namespace std;

int main() {
	int M; //#testcases
	int N; //number of coins
	int K; //number of weightings
	
	cin >> M;

	for(unsigned int m = 0; m < M; m++) {
		cin >> N >> K;
		vector<bool> tooBig(N, false);
		vector<bool> tooSmall(N, false);
		
		int pi;
		char op = '=';
		for(unsigned int k = 0; k < K; k++) {
			cin >> pi;
			vector<int> left(pi);
			vector<int> right(pi);

			for(unsigned int i = 0; i < pi; i++)
				cin >> left[i];
			for(unsigned int i = 0; i < pi; i++)
				cin >> right[i];
			cin >> op;

			//DEBUG--------
			for(unsigned int i = 0; i < pi; i++)
				cout << "left" << left[i] << endl;
			for(unsigned int i = 0; i < pi; i++)
				cout << "right" << right[i] << endl;
			cout << op << endl;
			//debug end
			
		}
	}
}
