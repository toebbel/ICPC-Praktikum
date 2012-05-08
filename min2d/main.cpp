#include <iostream>
#include <vector>
#include <climits>
#include <stdint.h>

using namespace std;

int findMin(int xmin, int ymin, int xmax, int ymax, vector<vector<vector<int > > > &fields, int pot);
static inline uint32_t log2(const uint32_t x); 

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
	lines = (lines >> 1) << 1;
	cols = (cols >> 1) << 1;
	while(1 << pot <= original_cols && 1 << pot <= original_lines) {
		cout << "lines: " << lines << ", cols: " << cols << ", pot: " << pot << endl;
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
		//////////////////////////////
		cout << "-----------------" << endl << "table for " << pot << endl;
		for(int i = 0; i < lines >> 1; i++) {
			for(int j = 0; j < cols >> 1; j++)
				cout << result[i][j];
			cout << endl;
		}
		//////////////////////////////
		source = result;
		pot++;
		lines = (lines >> 1);
		cols = (cols >> 1);
	}
	cout << "read for requests" << endl;
	int xmin, ymin, xmax, ymax;
		while(cin >> xmin >> ymin >> xmax >> ymax) {
		int result = findMin(xmin, ymin, xmax, ymax, fields, pot);
		cout << "result: " << result << endl;
	}
}

int findMin(int xmin, int ymin, int xmax, int ymax, vector<vector<vector<int > > > &fields, int maxpot) {

	cout << "request: (" << xmin << "," << ymin << ")x(" << xmax << "," << ymax << ") with maxpot " << maxpot << ".";
	//abort if there is no area
	if(xmin - xmax == 0 || ymin - ymax == 0) {
		cout << "abort - too small" << endl;
		return INT_MAX;
	}

/*	//calc max mathing square-size
	int size = 1 << maxpot;
	int pot = maxpot;
	while(pot > (log2(xmax) - log2(xmin)) && pot > (log2(ymax) - log2(ymin))){
		size = size >> 1;
		pot--;
	}

	cout << "mathing pot is " << pot << " (" << size << ")" << ".";
	//calc the left upper edge of matching area
	int xrelmin, yrelmin = 0;
	int xrelmax = xmax;
	int yrelmax = ymax;
	if(pot > 0) {
		xrelmin = ((xmin + (xmin % size)) >> (pot) / size);
		yrelmin = ((ymin + (ymin % size)) >> (pot) / size);
		xrelmax = ((xmax - (xmax % size)) >> (pot) / size);
		yrelmax = ((ymax - (ymax % size)) >> (pot) / size);
		//xrelmin = (xmin / size) + (xmin % size);
		//yrelmin = (ymin / size) + (ymin % size);
		//xrelmax = (xmax / size);// - (xmax % size);
		//yrelmax = (ymax / size);// - (ymax % size);
	} else {
		xrelmin = xmin;
		yrelmin = ymin;
		xrelmax = xmax;
		yrelmax = ymax;
	}
	// *
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


	unsigned int xrelmin = log2(xmin) + 1;
	unsigned int xrelmax = log2(xmax);
	unsigned int yrelmin = log2(ymin) + 1;
	unsigned int yrelmax = log2(ymax);
	if(1 << xrelmax < xmax)
		xrelmax++;
	if(1 << yrelmax < ymax)
		yrelmax++;
	int pot = 0;
	if(xrelmin < yrelmin)
		pot = xrelmin;
	else
		pot = yrelmin;
	cout << "matching fields from (" << xrelmin << "," << yrelmin << ")x(" << xrelmax << "," << yrelmax << ")" << "." << endl;
	//calc the minimum inside the area
	int currMin = INT_MAX;
	for(int x = xrelmin -1; x < xrelmax; x++)
		for(int y = yrelmin - 1; y < yrelmax; y++) {
			cout << fields[pot][x][y] << "(" << pot << "," << x << "," << y << ") < " << currMin << "?" << endl;
			if(fields[pot][x][y] < currMin) {
				currMin = fields[pot][x][y];
				cout << "wrote " << currMin << endl;
			}
		}
	if(maxpot > 0) {
	//calc the minimum at the borders
	int tmp[4];
	for(unsigned int i = 0; i < 4; i++)
		tmp[i] = INT_MAX;
	if(1 >> yrelmax != ymax) {
		cout << "top";
		tmp[0] = findMin(xmin, ymin, xmax, 1 >> yrelmax, fields, maxpot - 1); //top
	}

	if(1 >> xrelmax != xmax) {
		cout << "left";
		tmp[1] = findMin(xmin, ymin, 1 >> xrelmax, ymax, fields, maxpot - 1); //left
	}

	if(1 >> yrelmin != yrelmin) {
		cout << "bottom";
		tmp[2] = findMin(xmin, 1 >> yrelmin, xmax, ymax, fields, maxpot - 1); //bottom
	}
	if(1 >> xrelmin != xrelmin) {
		cout << "right";
		tmp[3] = findMin(1 >> xrelmin, ymin, xmax, ymax, fields, maxpot - 1); //right
	}
	for(unsigned int i = 0; i < 4; i++)
		if(tmp[i] < currMin)
			currMin = tmp[i];
	}
	cout << "min: " << currMin << endl;
	return currMin;
}

static inline uint32_t log2(const uint32_t x) {
  uint32_t y;
  asm ( "\tbsr %1, %0\n"
      : "=r"(y)
      : "r" (x)
  );
  return y;
}

