#include <iostream>
#include <stack>

using namespace std;

int main() {
	
	stack<char> map;
	char curr;
	int pool = 0;
	while(cin >> curr) {
		if(curr == '_' || curr == '\\')
			map.push(curr);
		else {
			int tmp = 1;
			while(map.size() > 0 && map.top() != '\\') {
				tmp += 2;
				map.pop();
			}
			if(map.size() == 0)
				tmp = 0;
			for(int i = 0; i < tmp; i++)
				map.push('_');
			cout << "add " << tmp << endl;
			pool += tmp;
		}
	}	

	cout << pool << endl;
		
}
