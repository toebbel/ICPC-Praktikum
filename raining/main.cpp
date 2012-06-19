#include <iostream>
#include <stack>

using namespace std;

int main() {
	stack<int> map;
	char curr;
	int pool = 0;
	int count = 0;
	while(cin >> curr) {
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
