#include <iostream>
#include <vector>
using namespace std;

vector<vector<bool> > field;
int m, n;

void clear(int x, int y);

int main() {
	while(cin >> m >> n) {
		if(m == 0)
			break;
		field.clear();
		for(int i = 0; i < m; i++)
			field.push_back(vector<bool>(n));
		for(int i = 0; i < m; i++)
			for(int j = 0; j < n; j++){
				char tmp = '*';
				cin >> tmp;
				field[i][j] = (tmp == '@');
			}
/*		for(int i = 0; i < m; i++) {
			for(int j = 0; j < n; j++) 
				cout << field[i][j];
			cout << endl;
		}*/
		int count = 0;
		for(int i = 0; i < m; i++)
			for(int j = 0; j < n; j++)
				if(field[i][j]) {
					count++;
					clear(i, j);
				}
		cout << count << endl;
	}
}

void clear(int x, int y) {
	if(x < 0 || y < 0 || x >= m || y >= n)
		return;
	if(field[x][y]) {
		field[x][y] = false;
		clear(x - 1, y - 1);
		clear(x - 1, y);
		clear(x - 1, y + 1);
		clear(x, y - 1);
		clear(x, y + 1);
		clear(x + 1, y - 1);
		clear(x + 1, y);
		clear(x + 1, y + 1);
	}
}
