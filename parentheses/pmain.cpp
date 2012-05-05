#include <iostream>
#include <string>
#include <stack>

using namespace std;


int main() {
	int n  = 0;
	cin >> n;
	cin.ignore();
	for(int i = 0; i < n; i++) {
		char curr = ' ';
		stack<char> myStack;
		string line = "";
		getline(cin, line);
		for(int i = 0; i < line.length(); i++) {
			curr = line[i];	
			if(curr == '(' || curr == '[') {
				myStack.push(curr);
			} else {
				if(myStack.size() == 0) {
					myStack.push('e');
					break;
				}
				
				if((curr == ')' && myStack.top() =='(') || (curr == ']' && myStack.top() == '['))
					myStack.pop();
				else {
					break;
				}
			}
		}
		if(myStack.size() == 0)
			cout << "Yes" <<endl;
		else
			cout << "No" << endl;
		//string line = "";
		//cin.getline(&line, 256);
	}
}

