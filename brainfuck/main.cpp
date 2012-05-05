#include <iostream>
#include <string>
#include <stack>
#include <vector>

using namespace std;

bool valid(string line);
string run(string code);

int main (){
	int n = 0;
	cin >> n;
	cin.ignore();
	for(int i = 1; i <= n; i++) {

		//read program and clean (ignore linebreaks, comments, other chars)
		string code = "";
		string line = "";
		getline(cin, line);
		while(line != "end") {
			for(int i = 0; i < line.length(); i++) {
				if(line[i] == '%') break;
				if(line[i] == '.' || line[i] == '>' || line[i] == '<' || line[i] == '+' || line[i] == '-' || line[i] == '[' || line[i] == ']')
					code.push_back(line[i]);
			}
			getline(cin, line);
		}
		//cout << code << endl;

		cout << "PROGRAM #" << i << ":" << endl;
		if(!valid(code)) {
			 cout << "COMPILE ERROR" << endl;
		} else {
		run(code);
		cout << endl;
		}
	}
}

string run(string code) {
	int codePos = 0;
	int ptr = 0;
	string result = "";
	vector<unsigned char> data(32768);
	while(codePos < code.length() && codePos >= 0) {
		if(code[codePos] == '>') { ptr = ++ptr > 32767 ? 0 : ptr; codePos++; continue; }
		if(code[codePos] == '<') { ptr = --ptr < 0 ? 32767 : ptr; codePos++; continue; }
		if(code[codePos] == '+') { data[ptr] = data[ptr] + 1; codePos++; continue; }
		if(code[codePos] == '-') { data[ptr] = data[ptr] - 1; codePos++; continue; }
		if(code[codePos] == '.') { cout << data[ptr]; codePos++; continue; }
		
		if(code[codePos] == '[' && data[ptr] == 0) {
			int tmp = 1;
			do {
				codePos++;
				if(code[codePos] == '[') tmp++;
				if(code[codePos] == ']') tmp--;
			} while(tmp > 0);
			codePos++;
			continue;
		}
		if(code[codePos] == ']' && data[ptr] != 0) {
			int tmp = 1;
			do {
				codePos--;
				if(code[codePos] == ']') tmp++;	
				if(code[codePos] == '[') tmp--;
			} while(tmp > 0);
			continue;
		}		
		codePos++;
	}
	return "";
}

bool valid(string line) {
	int open = 0;
	for(int i = 0; i < line.length() && open >= 0; i++) {
		if(line[i] == '[') open++;
		if(line[i] == ']') open--;
	}

	return open == 0;
}

