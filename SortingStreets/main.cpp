#include <iostream>
#include <vector>

using namespace std;

vector<int> result;

int main() {
	int T;
	cin >> T;
	for(unsigned int t = 0; t < T; t++) {
		result.clear();	



		//print the result
		if(result.size() == 0)
			cout << "SHITTY NETWORK" << endl;
		else {
			for(unsigned int i = 0; i < result.size(); i++)
				cout << result[i] << " ";
			cout << endl;
		}
	}
}
