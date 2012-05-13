#include <iostream>
#include <math.h>
#include <vector>
#include <string>

using namespace std;

int main() {
	char line0[] = { '-', ' ', '-', '-', ' ', '-', '-', '-', '-', '-' };
	char line1_1[] = { '|', ' ', ' ', ' ', '|', '|', '|', ' ', '|', '|' };
	char line1_2[] = { '|', '|', '|', '|', '|', ' ', ' ', '|', '|', '|' };
	char line2[] = { ' ', ' ', '-', '-', '-', '-', '-', ' ', '-', '-' };
	char line3_1[] = { '|', ' ', '|', ' ', ' ', ' ', '|', ' ', '|',  ' ' };
	char line3_2[] = { '|', '|',' ', '|', '|', '|', '|', '|', '|', '|' };
	char line4[] = { '-', ' ', '-', '-', ' ', '-', '-', ' ', '-', '-' };

	int size, number;
	while(cin >> size) {
		string in;
		cin >> in;
		bool otherThanZero = false;
		vector<char> digits;

		for(int i = 0; i < in.length(); i++) {
			if(in[i] != '0')
				otherThanZero = true;
			digits.push_back(in[i] - 48);

		}
		if(!otherThanZero && size == 0)
			break;

			
		//line 0
		for(int i = 0; i < digits.size(); i++) {
			cout << " ";
			for(int j = 0; j < size; j++)
				cout << line0[digits[i]];
			if(i < digits.size() - 1)
				cout << "  ";
			else
				cout << " ";
		}
		cout << endl;

		for(int l = 0; l < size; l++) {
		//line1
		for(int i = 0; i < digits.size(); i++) {
			cout << line1_1[digits[i]];
			for(int j = 0; j < size; j++)
				cout << " ";
			cout << line1_2[digits[i]];
			if(i < digits.size() - 1)
				cout << " ";
		}
		cout << endl;
		}

		//line 2
		for(int i = 0; i < digits.size(); i++) {
			cout << " ";
			for(int j = 0; j < size; j++)
				cout << line2[digits[i]];
			if(i < digits.size() - 1)
				cout << "  ";
			else 
				cout << " ";
		}
		cout << endl;

		for(int l = 0; l < size; l++) {
		//line3
		for(int i = 0; i < digits.size(); i++) {
			cout << line3_1[digits[i]];
			for(int j = 0; j < size; j++)
				cout << " ";
			cout << line3_2[digits[i]];
			if(i < digits.size() - 1)
				cout << " ";
		}
		cout << endl;
		}

		//line4
		for(int i = 0; i < digits.size(); i++) {
			cout << " ";
			for(int j = 0; j < size; j++)
				cout << line4[digits[i]];
			if(i < digits.size() - 1)
				cout << "  ";
			else
				cout << " ";
		}
		cout << endl << endl;
	}	
}
