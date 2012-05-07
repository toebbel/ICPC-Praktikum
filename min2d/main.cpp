#include <iostream>
#include <vector>
#include <math.h>
#include <climits>

using namespace std;

int findMin(int xmin, int ymin, int xmax, int ymax, vector<vector<vector<int > > > &fields, int pot);

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
		int result = findMin(xmin - 1, ymin - 1, xmax - 1, ymax - 1, fields, pot);
		cout << "result: " << result << endl;
	}
}

int findMin(int xmin, int ymin, int xmax, int ymax, vector<vector<vector<int > > > &fields, int maxpot) {

	cout << "request: (" << xmin << "," << ymin << ")x(" << xmax << "," << ymax << ") with maxpot " << maxpot << ".";
	//abort if there is no area
/*	if(xmin - xmax == 0 || ymin - ymax == 0) {
		cout << "abort - too small" << endl;
		return INT_MAX;
	}
*/
	//calc max mathing square-size
	int size = 1;
	int pot = 0;
	while(!((xmax - xmin) & size) && !((ymax - ymin) & size) && pot <= maxpot) {
		size = size << 1;
		pot++;
	}
	if(size == 0)
		return INT_MAX;

	cout << "mathing pot is " << pot << " (" << size << ")" << ".";
	//calc the left upper edge of matching area
	int xrelmin, yrelmin, xrelmax, yrelmax;
	xrelmin = xmin >> pot;
	yrelmin = ymin >> pot;
	xrelmax = xmax >> pot;
	yrelmax = ymax >> pot;
	/*
	while(xrelmin * size < xmin)
		xrelmin++;
	while(yrelmin * size < ymin)
		yrelmin++;

	//calc the lower bottom edge of matching area
	int xrelmax = xrelmin + (xmax / size);//xrelmin - 1;
	int yrelmax = yrelmin + (ymax / size);//yrelmin - 1;

	while(xrelmax * size < xmax)
		xrelmax++;
	while(yrelmax * size < ymax)
		yrelmax++;*/


	cout << "matching fields from (" << xrelmin * size << "," << yrelmin * size << ")x(" << xrelmax * size << "," << yrelmax * size << ")" << ".";
	//calc the minimum inside the area
	int currMin = INT_MAX;
	for(int x = xrelmin; x <= xrelmax; x++)
		for(int y = yrelmin; y <= yrelmin; y++)
			if(fields[pot][x][y] < currMin)
				currMin = fields[pot][x][y];
	if(pot > 0) {
	//calc the minimum at the borders
	int tmp[4];
	if(yrelmax * size != ymax + 1) {
		cout << "top";
		tmp[0] = findMin(xmin, ymin, xmax, yrelmax * size, fields, maxpot - 1); //top
	}

	if(xrelmax * size != xmax + 1) {
		cout << "left";
		tmp[1] = findMin(xmin, ymin, xrelmax * size, ymax, fields, maxpot - 1); //left
	}

	if(yrelmin * size != yrelmin) {
		cout << "bottom";
		tmp[2] = findMin(xmin, yrelmin * size, xmax, ymax, fields, maxpot - 1); //bottom
	}
	if(xrelmin * size != xrelmin) {
		cout << "right";
		tmp[3] = findMin(xrelmin * size, ymin, xmax, ymax, fields, maxpot - 1); //right
	}
	for(unsigned int i = 0; i < 4; i++)
		if(tmp[i] < currMin)
			currMin = tmp[i];
	}
	cout << "min: " << currMin << endl;
	return currMin;
}
