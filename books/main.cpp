#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int ggt(stack<int> in);
int ggt(int a, int b);

int main() {
	int N = 0;
	cin >> N;
	vector<int> diffs;
	vector<int> checkSums;
	for(int n = 0; n < N; n++) {
		int num_books;
		diffs.clear();
		checkSums.clear();
		cin >> num_books;
		for(int i = 0; i < num_books; i++) {
			int sum, tmp;
			for(int j = 0; j < 9; j++) {
				cin >> tmp;
				sum += tmp;
			}
			cin >> tmp;
			checkSums.push_back(tmp);
			diffs.push_back(sum - tmp);
			sum = tmp = 0;
		}

		stack<int> diff_stack;
		for(int i = 0; i < diffs.size(); i++){
			diff_stack.push(diffs[i]);
		}
		int result = ggt(diff_stack);

		bool impossible = false;
		for(int i = 0; i < checkSums.size(); i++)
			if(checkSums[i] > result)
				impossible = true;
		if(result <= 1 || impossible)
			cout << "impossible" << endl;
		else
			cout << result << endl;
	}
}

int ggt(stack<int> in) {
	if(in.size() == 0)
		return 1;
	if(in.size() == 1)
		return in.top();
	stack<int> recursive;
	int a, b;
	a = in.top();
	in.pop();
	b = in.top();
	in.pop();
	for(int i = 0; i < in.size(); i++) {
		recursive.push(in.top());
		in.pop();
	}
	//cout << "ggt(" << a << ", " << b << ")" << endl;
	recursive.push(ggt(a, b));
	return ggt(recursive);
}

int ggt(int a, int b) {
	if(b == 0)
		return a;
	if(a == 0)
		return 1;
	return ggt(b, a % b);
}
