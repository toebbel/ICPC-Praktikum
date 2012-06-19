#include <iostream>

using namespace std;

int main() {
	int N;
	cin >> N; //#testcasses
	
	vector<int> line;
	char curr;
	int depth = 0;
	while(cin >> curr) {
		if(curr == '-')
			line.push_back(depth);
		else if(curr == '/') {
			depth --;
			line.push_back(depth);
		} else if(curr == '\\') {
			depth++;
			line.push_back(depth);
		}
	}

	int pool;
	for(int right = 1; left < line.size(); right++) {
		for(int left = right -1; left >= 0 && line[left] < line[right]; left--);
		if(left >= 0) {
			pool += (right - left - 1);
			cout << "from " << left << " to " << right << " are " << (right - left - 1) << " units"<<endl;
		}
	}
}
