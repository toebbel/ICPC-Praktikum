#include <iostream>
#include <string>

using namespace std;

int main() {
	int N = 0;
	cin >> N;
	cin.ignore();
	for(unsigned int n = 0; n < N; n++) {
		string regex, candidate;
		getline(cin, regex);
		getline(cin, candidate);
//		cout << regex << " == " << candidate << "?" << endl;
		int pr = 0;
		int pc = 0;
		bool begin = true;
		int i = 0;
		for(i = 0; i < candidate.length(); i++) {
			if(regex[i] == '*') {
//				cout << "*";
				begin = true;
				break;
			}
			if(regex[i] == '+') {
				cout << "i= " << i << " len=" << candidate.length() << endl;
				if(candidate.length() - 1 != i){
//					cout << "+";
					begin = true;
				} else {
					begin = false;
//					cout << "+WRONG"<< endl;
				}
				break;
			}
			if(regex[i] == candidate[i]) {
//				cout << "=";
				begin = true;
				continue;
			} else {
//				cout << "!";
				begin = false;
				break;
			}
	
		}
		if(i < regex.length())
			begin = false; 
//		cout << "compare the end" << endl;
		bool end = true;

		if(begin) {
		int middle = i;
		pr = regex.length() - 1;
		if(i < candidate.length()) {
//			cout << "pr = " << pr << "middle = " << middle << endl;
			for(int i = candidate.length() - 1; pr > middle && i > 0; i--, pr--) {
				if(regex[pr] == candidate[i]){
//					cout << "=";
					end = true;
					continue;
				} else {
//					cout << "!(" << regex[pr] << "vs." << candidate[i];
					end = false;
					break;
				}

			}
		} else
			end = true;
		
		}
		if(begin && end)
			cout << "Yes" << endl;
		else
			cout << "No" << endl;
	}
}
