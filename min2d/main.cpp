#include <iostream>
#include <vector>
#include <math.h>
#include <climits>

using namespace std;

int main() {
	int cols, lines;
	cin >> cols >> lines;

	//read the data into matrix 'field 2^0'
	vector< vector<int> > field;
	field.resize(lines);
	for(int x = 0; x < lines; x++) {
		field[x].resize(cols);
		for(int y = 0; y < cols; y++)
			cin >> field[x][y];
	}
	vector< vector< vector <int > > > fields;
	fields.push_back(field);

	//calc fields, with each square 2^pot in size and push onto vector
	unsigned int pot = 2;
	vector < vector <int > > source = field;
	int original_lines = lines;
	int original_cols = cols;
	lines = lines & ~3;
	cols = cols & ~3;
	while(pot <= original_cols && pot <= original_lines) {
//		cout << "lines: " << lines << ", cols: " << cols << ", pot: " << pot << endl;
		vector< vector< int > > result;
		int y = 0;
		int x = 0;
		result.resize(lines >> 1);
		//init the field with max values
		for(int i = 0; i < lines >> 1; i++) {
			result[i].resize(cols >> 1);
			for(int j = 0; j < cols >> 1; j++) {
				result[i][j] = INT_MAX; //max possible number
			}
		}

		//calc result out of source
		for(int x = 0; x < lines; x++)
			for(int y = 0; y < cols; y++) {
				if(result[x >> 1][y >> 1] > source[x][y]) {
					result[x >> 1][y >> 1] = source[x][y];
				}
			}

	
/*		///////////////////////////////
		for(int v = 0; v < lines >> 1; v++) {
			for(int u = 0; u < lines >> 1; u++)
				cout << result[v][u] << " ";
			cout << endl;
		}
		cout << "--------------------" << endl;	
		//////////////////////////////*/
		fields.push_back(result);
		source = result;
		cout << pot << endl;
		pot = pot << 1;
		lines = (lines >> 1) & ~3;
		cols = (cols >> 1) & ~3;
	}
	cout << "read for requests" << endl;
	int xmin, ymin, xmax, ymax;
	while(cin >> xmin >> ymin >> xmax >> ymax) {
		int mask = 512;
		while(!((xmax - xmin) & mask) && !((ymax - ymin) & mask)) {
			mask = mask >> 1;
		}
		cout << "bestmatch: " << mask << endl;
	}
}
