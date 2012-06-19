#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main() {
	int T;
	cin >> T;
	for(int t = 0; t < T; t++) {
		stack<int> map;
		char curr;
		int pool = 0;
		int count = 0;
		string line;
		cin >> line;
		while(count < line.length()) {
			curr = line[count];
			if(curr == '\\')
				map.push(count);
			if(curr == '/')
				if(map.size() > 0) {
					pool += count - map.top();
		//			cout << "add " << count - map.top() << endl;
					map.pop();
				}
			count++;
		}

		cout << pool << endl;
	}
}
